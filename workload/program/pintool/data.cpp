#include "pin.H"
#include <string>
#include <fstream>

ofstream READ, WRITE;

void log_read(ADDRINT addr) { 
  READ << addr << '\n';
}

void log_write(ADDRINT addr) { 
  WRITE << addr << '\n';
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
  string readfile = prefix.Value() + ".read.data.workload";
  string writefile = prefix.Value() + ".write.data.workload";
  READ.open(readfile.c_str());
  WRITE.open(writefile.c_str());
  INS_AddInstrumentFunction(instruction, 0);
  PIN_StartProgram();
  READ.close();
  WRITE.close();
  return 0;
}
