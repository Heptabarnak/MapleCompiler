#ifndef MAPLECOMPILER_CMPEQINSTR_H
#define MAPLECOMPILER_CMPEQINSTR_H


#include <ir/IRInstr.h>

class CmpEqInstr: public IRInstr {
public:
    CmpEqInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_CMPEQINSTR_H
