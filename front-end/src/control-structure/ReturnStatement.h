#ifndef MAPLECOMPILER_RETURNSTATEMENT_H
#define MAPLECOMPILER_RETURNSTATEMENT_H


#include <expression/Expr.h>
#include "Instruction.h"

class ReturnStatement : public Instruction {

private:
    Expr *expr;

public:
    ReturnStatement(Expr *expr);
    ~ReturnStatement();
};


#endif //MAPLECOMPILER_RETURNSTATEMENT_H
