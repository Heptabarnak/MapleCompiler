#ifndef MAPLECOMPILER_WHILESTATEMENT_H
#define MAPLECOMPILER_WHILESTATEMENT_H


#include <expression/Expr.h>
#include "Instruction.h"

class WhileStatement : public Instruction {

private:
    Expr *condition;
    Instruction *instruction;

public:
    WhileStatement(Expr *condition, Instruction *instruction);
    ~WhileStatement();

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_WHILESTATEMENT_H
