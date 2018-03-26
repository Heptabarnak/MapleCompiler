#ifndef MAPLECOMPILER_IRINSTR_H
#define MAPLECOMPILER_IRINSTR_H

#include <vector>
#include <string>
#include <iostream>

#include <token/Type.h>
#include "BasicBlock.h"


class IRInstr {

public:
    /** The instructions themselves -- feel free to subclass instead */
    typedef enum {
        ldconst,
        add,
        sub,
        mul,
        rmem,
        wmem,
        call,
        cmp_eq,
        cmp_lt,
        cmp_le
    } Operation;


    /**  constructor */
    IRInstr(BasicBlock *bb_, Type t);

    /** Actual code generation */
    virtual void gen_asm(std::ostream &o) = 0; /**< x86 assembly code generation for this IR instruction */

protected:
    BasicBlock *bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
    Type t;
};


#endif //MAPLECOMPILER_IRINSTR_H
