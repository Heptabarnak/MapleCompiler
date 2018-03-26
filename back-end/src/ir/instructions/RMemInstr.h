#ifndef MAPLECOMPILER_RMEMINSTR_H
#define MAPLECOMPILER_RMEMINSTR_H


#include <ir/IRInstr.h>

class RMemInstr : public IRInstr{
public:
    RMemInstr(BasicBlock *bb_, Type t);

};


#endif //MAPLECOMPILER_RMEMINSTR_H
