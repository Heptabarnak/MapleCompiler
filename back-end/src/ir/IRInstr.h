#ifndef MAPLECOMPILER_IRINSTR_H
#define MAPLECOMPILER_IRINSTR_H

#include <vector>
#include <string>
#include <iostream>

#include "BasicBlock.h"

class BasicBlock;

class IRInstr {

public:
    explicit IRInstr(BasicBlock *bb_);

    virtual ~IRInstr() = default;

protected:
    BasicBlock *bb;
};


#endif //MAPLECOMPILER_IRINSTR_H
