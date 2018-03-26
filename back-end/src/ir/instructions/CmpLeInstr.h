#ifndef MAPLECOMPILER_CMPLEINSTR_H
#define MAPLECOMPILER_CMPLEINSTR_H


#include <ir/IRInstr.h>

class CmpLeInstr: public IRInstr {
public:
    CmpLeInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_CMPLEINSTR_H
