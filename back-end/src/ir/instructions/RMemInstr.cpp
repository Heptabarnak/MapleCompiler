#include "RMemInstr.h"

RMemInstr::RMemInstr(BasicBlock *bb_, std::string var1, std::string var2)
        : IRInstr(bb_), var1(var1), var2(var2) {}
