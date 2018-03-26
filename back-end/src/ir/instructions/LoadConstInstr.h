#ifndef MAPLECOMPILER_LDCONSTINSTR_H
#define MAPLECOMPILER_LDCONSTINSTR_H


#include <ir/IRInstr.h>

class LoadConstInstr : public IRInstr{
public:
    LoadConstInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_LDCONSTINSTR_H
