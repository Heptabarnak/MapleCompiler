#include "CallInstr.h"

using std::string;
using std::vector;

CallInstr::CallInstr(BasicBlock *bb_, string dest, string label, string var, vector<string> &arguments)
        : IRInstr(bb_), dest(dest), label(label), var(var), arguments(arguments) {}
