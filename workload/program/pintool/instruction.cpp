#include "pin.H"
#include <string>
#include <fstream>

ofstream READ, WRITE;

void instruction(INS ins, void *v) {
  ADDRINT addr = INS_Address(ins);
  if (INS_IsMemoryRead(ins) && INS_IsStandardMemop(ins)) {
    READ << addr << endl;
    return;
  }
  if ( INS_IsMemoryWrite(ins) && INS_IsStandardMemop(ins)) {
    WRITE << addr << endl;
  }
}

KNOB<string> prefix(KNOB_MODE_WRITEONCE, "pintool",
  "o", "a", "specify output file prefix");

int main(int argc, char * argv[]) {
  PIN_InitSymbols();
  if (PIN_Init(argc, argv)) return -1;
  string readfile = prefix.Value() + ".read.ins.workload";
  string writefile = prefix.Value() + ".write.ins.workload";
  READ.open(readfile.c_str());
  WRITE.open(writefile.c_str());
  INS_AddInstrumentFunction(instruction, 0);
  PIN_StartProgram();
  READ.close();
  WRITE.close();
  return 0;
}
