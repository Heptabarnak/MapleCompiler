#include "CallInstr.h"

using std::string;
using std::vector;

CallInstr::CallInstr(BasicBlock *bb_, string dest, string label, vector<string> &arguments, Type varType)
        : IRInstr(bb_), dest(dest), label(label), arguments(arguments), varType(varType) {}
