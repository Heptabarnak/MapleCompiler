#ifndef MAPLECOMPILER_INCRINSTR_H
#define MAPLECOMPILER_INCRINSTR_H


#include <ir/IRInstr.h>

class IncrInstr : public IRInstr {
public:

    enum OpType {
        PLUS,
        MINUS
    };

    IncrInstr(BasicBlock *bb_, OpType type, std::string var, std::string var1, bool isPostfix);


    bool isPostfix;
    OpType type;
    std::string var;
    std::string var1;

};


#endif //MAPLECOMPILER_INCRINSTR_H
