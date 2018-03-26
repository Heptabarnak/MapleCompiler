#ifndef MAPLECOMPILER_ADDINSTR_H
#define MAPLECOMPILER_ADDINSTR_H


#include <ir/IRInstr.h>

class AddInstr : public IRInstr {
public:
    AddInstr(BasicBlock *bb_, Type t);
};


#endif //MAPLECOMPILER_ADDINSTR_H
