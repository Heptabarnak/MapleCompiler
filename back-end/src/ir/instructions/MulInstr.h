#ifndef MAPLECOMPILER_MULINSTR_H
#define MAPLECOMPILER_MULINSTR_H


#include <ir/IRInstr.h>

class MulInstr: public IRInstr {
public:
    MulInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_MULINSTR_H
