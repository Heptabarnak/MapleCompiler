#include "OpInstr.h"

using std::string;

OpInstr::OpInstr(BasicBlock *bb_, OpInstr::OpType t, string var, string var1, string var2, Type varType, Type var1Type, Type var2Type)
        : IRInstr(bb_), type(t), var(var), var1(var1), var2(var2), varType(varType), var1Type(var1Type), var2Type(var2Type) {}
