#include "WMemInstr.h"

using std::string;

WMemInstr::WMemInstr(BasicBlock *bb_, string var1, string var2)
        : IRInstr(bb_), var1(var1), var2(var2) {}
