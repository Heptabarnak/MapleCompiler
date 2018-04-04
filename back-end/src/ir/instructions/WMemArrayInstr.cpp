#include "WMemArrayInstr.h"

using std::string;

WMemArrayInstr::WMemArrayInstr(BasicBlock *bb_, string value, string tab, std::string pos, Type type)
        : IRInstr(bb_), value(value), tab(tab), pos(pos), type(type) {}
