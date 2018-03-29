#include "RMemArrayInstr.h"

using std::string;

RMemArrayInstr::RMemArrayInstr(BasicBlock *bb_, string var1, string var2, string index)
        : IRInstr(bb_), var1(var1), var2(var2), index(index) {}
