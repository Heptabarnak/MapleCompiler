#ifndef MAPLECOMPILER_CALLINSTR_H
#define MAPLECOMPILER_CALLINSTR_H


#include <ir/IRInstr.h>

class CallInstr: public IRInstr {
public:
    CallInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_CALLINSTR_H
