#include "CallInstr.h"

using std::string;
using std::vector;

CallInstr::CallInstr(BasicBlock *bb_, string label, string var, vector<string> &arguments)
        : IRInstr(bb_), label(label), var(var), arguments(arguments) {}