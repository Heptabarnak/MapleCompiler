#ifndef MAPLECOMPILER_SUBINSTR_H
#define MAPLECOMPILER_SUBINSTR_H


#include <ir/IRInstr.h>

class SubInstr : public IRInstr {
public:
    SubInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_SUBINSTR_H
