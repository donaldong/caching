#include "pin.H"
#include <string>
#include <fstream>

ofstream OUT;

void log_read(ADDRINT addr) { 
  bool a = true;
  OUT.write((char*)&a, 1);
  OUT.write((char*)&addr, 8);
}

void log_write(ADDRINT addr) { 
  bool a = false;
  OUT.write((char*)&a, 1);
  OUT.write((char*)&addr, 8);
}

void instruction(INS ins, void *v) {
  if (INS_IsMemoryRead(ins) && INS_IsStandardMemop(ins)) {
    INS_InsertPredicatedCall(
      ins, IPOINT_BEFORE, (AFUNPTR) log_read,
      IARG_MEMORYREAD_EA, IARG_END);
    return;
  }
  if ( INS_IsMemoryWrite(ins) && INS_IsStandardMemop(ins)) {
    INS_InsertPredicatedCall(
      ins, IPOINT_BEFORE, (AFUNPTR) log_write,
      IARG_MEMORYWRITE_EA, IARG_END);
  }
}

KNOB<string> prefix(KNOB_MODE_WRITEONCE, "pintool",
  "o", "a", "specify output file prefix");

int main(int argc, char * argv[]) {
  PIN_InitSymbols();
  if (PIN_Init(argc, argv)) return -1;
  string outfile = prefix.Value() + ".raw.data.workload";
  OUT.open(writefile.c_str());
  INS_AddInstrumentFunction(instruction, 0);
  PIN_StartProgram();
  READ.close();
  WRITE.close();
  return 0;
}
