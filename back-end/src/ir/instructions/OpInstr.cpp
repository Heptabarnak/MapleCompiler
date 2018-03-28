#include "OpInstr.h"

OpInstr::OpInstr(BasicBlock *bb_, OpInstr::OpType t, std::string var, std::string var1, std::string var2)
        : IRInstr(bb_), type(t), var(var), var1(var1), var2(var2) {}
