#include "LoadConstInstr.h"

LoadConstInstr::LoadConstInstr(BasicBlock *bb_, std::string var, long value, Type type)
        : IRInstr(bb_), var(var), value(value), type(type) {}
