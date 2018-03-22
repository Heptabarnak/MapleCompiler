#ifndef MAPLECOMPILER_IFSTATEMENTINSTRUCTION_H
#define MAPLECOMPILER_IFSTATEMENTINSTRUCTION_H

#include <expression/Expr.h>
#include "Statement.h"
#include "Instruction.h"

class IfStatement : public Instruction {
private:
    Expr *condition;
    Statement *statement;
    Instruction *elseStatement;
public:
    IfStatement(Expr *c, Statement *st, Instruction *elseSt);
    ~IfStatement();
};

#endif //MAPLECOMPILER_IFSTATEMENTINSTRUCTION_H
