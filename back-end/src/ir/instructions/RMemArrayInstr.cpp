#include "RMemArrayInstr.h"

RMemArrayInstr::RMemArrayInstr(BasicBlock *bb_, std::string var1, std::string var2, std::string index)
        : IRInstr(bb_), var1(var1), var2(var2), index(index) {}
