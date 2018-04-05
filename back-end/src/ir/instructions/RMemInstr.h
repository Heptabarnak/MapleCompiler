#ifndef MAPLECOMPILER_RMEMINSTR_H
#define MAPLECOMPILER_RMEMINSTR_H

#include <string>
#include <ir/IRInstr.h>

class RMemInstr : public IRInstr {
public:
    RMemInstr(BasicBlock *bb_, std::string var1, std::string var2, Type varType);

    std::string var1;
    std::string var2;
    Type varType;

};


#endif //MAPLECOMPILER_RMEMINSTR_H
