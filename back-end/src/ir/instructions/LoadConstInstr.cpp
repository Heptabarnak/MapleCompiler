#include "LoadConstInstr.h"

LoadConstInstr::LoadConstInstr(BasicBlock *bb_, std::string var, long value)
        : IRInstr(bb_), var(var), value(value) {}
