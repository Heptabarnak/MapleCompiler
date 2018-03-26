#ifndef MAPLECOMPILER_IRINSTR_H
#define MAPLECOMPILER_IRINSTR_H

#include <vector>
#include <string>
#include <iostream>

#include <token/Type.h>
#include <targets/Target.h>
#include "BasicBlock.h"

class BasicBlock;

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
    IRInstr(BasicBlock *bb_, Type t, Target target = Target::x86);

    /** Actual code generation */
    // virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */

protected:
    BasicBlock *bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
    Type t;
    Target target;
};


#endif //MAPLECOMPILER_IRINSTR_H
