#include "IncrInstr.h"

using std::string;

IncrInstr::IncrInstr(BasicBlock *bb_, IncrInstr::OpType type, string var, string var1, bool isPostfix)
        : IRInstr(bb_), type(type), var(var), var1(var1), isPostfix(isPostfix) {}
