#ifndef MAPLECOMPILER_UNARYOPINSTR_H
#define MAPLECOMPILER_UNARYOPINSTR_H


#include <ir/IRInstr.h>

class UnaryOpInstr : public IRInstr {
public:
    enum UnaryOpType {
        PLUS,
        MINUS,
        NOT,
        BITWISE_NOT
    };

    UnaryOpInstr(BasicBlock *bb_, UnaryOpType type, std::string var, std::string var1);


    UnaryOpType type;
    std::string var;
    std::string var1;
};


#endif //MAPLECOMPILER_UNARYOPINSTR_H
