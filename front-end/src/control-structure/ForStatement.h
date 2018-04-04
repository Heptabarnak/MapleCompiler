#ifndef MAPLECOMPILER_FORSTATEMENT_H
#define MAPLECOMPILER_FORSTATEMENT_H


#include <expression/Expr.h>
#include "Instruction.h"

class ForStatement: public Instruction {
private:
    Expr *init;
    Expr *condition;
    Expr *post;
    Instruction *statement;
public:
    ForStatement(Expr *init, Expr *condition, Expr *post, Instruction *statement);

    std::string buildIR(CFG *cfg) override;

    virtual ~ForStatement();
};


#endif //MAPLECOMPILER_FORSTATEMENT_H
