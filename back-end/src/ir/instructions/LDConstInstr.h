#ifndef MAPLECOMPILER_LDCONSTINSTR_H
#define MAPLECOMPILER_LDCONSTINSTR_H


#include <ir/IRInstr.h>

class LDConstInstr : public IRInstr{
public:
    LDConstInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_LDCONSTINSTR_H
