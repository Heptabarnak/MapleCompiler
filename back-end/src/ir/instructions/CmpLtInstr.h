#ifndef MAPLECOMPILER_CMPLTINSTR_H
#define MAPLECOMPILER_CMPLTINSTR_H


#include <ir/IRInstr.h>

class CmpLtInstr: public IRInstr {
public:
    CmpLtInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_CMPLTINSTR_H
