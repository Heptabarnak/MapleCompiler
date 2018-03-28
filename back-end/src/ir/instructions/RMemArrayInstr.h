#ifndef MAPLECOMPILER_RMEMARRAYINSTR_H
#define MAPLECOMPILER_RMEMARRAYINSTR_H

#include <string>
#include <ir/IRInstr.h>

class RMemArrayInstr : public IRInstr {
public:
    RMemArrayInstr(BasicBlock *bb_, std::string var1, std::string var2, std::string index);

    std::string var1;
    std::string var2;
    std::string index;

};


#endif //MAPLECOMPILER_RMEMARRAYINSTR_H
