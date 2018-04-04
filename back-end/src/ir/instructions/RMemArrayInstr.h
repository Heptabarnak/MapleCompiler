#ifndef MAPLECOMPILER_RMEMARRAYINSTR_H
#define MAPLECOMPILER_RMEMARRAYINSTR_H


#include <ir/IRInstr.h>

class RMemArrayInstr  : public IRInstr {
public:
    RMemArrayInstr(BasicBlock *bb_, std::string dest, std::string tab, std::string pos, Type type);

    std::string dest;
    std::string tab;
    std::string pos;
    Type type;
};

#endif //MAPLECOMPILER_RMEMARRAYINSTR_H
