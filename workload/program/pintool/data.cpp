#include "pin.H"
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

int main(int argc, char * argv[]) {
  READ.open("data.read");
  WRITE.open("data.write");
  PIN_Init(argc, argv);
  INS_AddInstrumentFunction(instruction, 0);
  PIN_StartProgram();
  READ.close();
  WRITE.close();
  return 0;
}
