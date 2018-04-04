#include "RMemArrayInstr.h"

using std::string;

RMemArrayInstr::RMemArrayInstr(BasicBlock *bb_, string dest, string tab, std::string pos, Type type)
        : IRInstr(bb_), dest(dest), tab(tab), pos(pos), type(type) {}
