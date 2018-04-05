#ifndef MAPLECOMPILER_OPINSTR_H
#define MAPLECOMPILER_OPINSTR_H

#include <string>
#include <ir/IRInstr.h>

class OpInstr : public IRInstr {
public:
    enum OpType {
        ADD,
        SUB,
        MULT,
        DIV,
        MOD,
        EQUAL_EQUAL,
        NOT_EQUAL,
        LESS_THAN,
        LESS_THAN_OR_EQ,
        MORE_THAN,
        MORE_THAN_OR_EQ,
        AND,
        OR,
        XOR,
        SHIFT_LEFT,
        SHIFT_RIGHT
    };


    OpInstr(BasicBlock *bb_, OpType t, std::string var, std::string var1, std::string var2, Type varType);

    OpType type;
    std::string var;
    std::string var1;
    std::string var2;
    Type varType;
};


#endif //MAPLECOMPILER_OPINSTR_H
