#include "pin.H"
#include <string>
#include <fstream>

ofstream OUT;

void log_read(ADDRINT addr) { 
    bool a = false;
    OUT.write((char*)&a, 1);
    OUT.write((char*)&a, 1);
    OUT.write((char*)&addr, 8);
}

void log_write(ADDRINT addr) { 
    bool a = true, b = false;
    OUT.write((char*)&a, 1);
    OUT.write((char*)&b, 1);
    OUT.write((char*)&addr, 8);
}

void instruction(INS ins, void *v) {
    ADDRINT addr = INS_Address(ins);
    if (INS_IsMemoryRead(ins) && INS_IsStandardMemop(ins)) {
        bool r = true, i = true;
        OUT.write((char*)&r, 1);
        OUT.write((char*)&i, 1);
        OUT.write((char*)&addr, 8);
        INS_InsertPredicatedCall(
            ins, IPOINT_BEFORE, (AFUNPTR) log_read,
            IARG_MEMORYREAD_EA, IARG_END);
        return;
    }
    if ( INS_IsMemoryWrite(ins) && INS_IsStandardMemop(ins)) {
        bool r = false, i = true;
        OUT.write((char*)&r, 1);
        OUT.write((char*)&i, 1);
        OUT.write((char*)&addr, 8);
        INS_InsertPredicatedCall(
            ins, IPOINT_BEFORE, (AFUNPTR) log_write,
            IARG_MEMORYWRITE_EA, IARG_END);
    }
}

KNOB<string> prefix(KNOB_MODE_WRITEONCE, "pintool",
  "o", "a", "specify output OUT.prefix");

int main(int argc, char * argv[]) {
    PIN_InitSymbols();
    if (PIN_Init(argc, argv)) return -1;
    string filename = prefix.Value() + ".raw.workload";
    OUT.open(filename.c_str());
    INS_AddInstrumentFunction(instruction, 0);
    PIN_StartProgram();
    OUT.close();
    return 0;
}
