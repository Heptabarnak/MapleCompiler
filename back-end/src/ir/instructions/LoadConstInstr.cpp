#include "LoadConstInstr.h"

using std::string;

LoadConstInstr::LoadConstInstr(BasicBlock *bb_, string var, long value, Type type)
        : IRInstr(bb_), var(var), value(value), type(type) {}
