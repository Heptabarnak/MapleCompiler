#include "CallInstr.h"

CallInstr::CallInstr(BasicBlock *bb_, std::string label, std::string var, std::vector<std::string> &arguments)
        : IRInstr(bb_), label(label), var(var), arguments(arguments) {}