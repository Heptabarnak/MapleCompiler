#ifndef MAPLECOMPILER_CALLINSTR_H
#define MAPLECOMPILER_CALLINSTR_H

#include <vector>
#include <string>
#include <ir/IRInstr.h>

class CallInstr : public IRInstr {
public:
    CallInstr(BasicBlock *bb_,std::string dest, std::string label, std::vector<std::string> &arguments);

    std::string dest;
    std::string label;
    std::vector<std::string> arguments;
};


#endif //MAPLECOMPILER_CALLINSTR_H
