#ifndef MAPLECOMPILER_LDCONSTINSTR_H
#define MAPLECOMPILER_LDCONSTINSTR_H

#include <string>
#include <ir/IRInstr.h>

class LoadConstInstr : public IRInstr {
public:
    LoadConstInstr(BasicBlock *bb_, std::string var, long value);

    std::string var;
    long value;

};


#endif //MAPLECOMPILER_LDCONSTINSTR_H
