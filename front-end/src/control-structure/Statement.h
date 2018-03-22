#ifndef MAPLECOMPILER_STATEMENT_H
#define MAPLECOMPILER_STATEMENT_H

#include <expression/Expr.h>
#include "Instruction.h"

class Statement : public Instruction {
public:
    Statement(Expr *e);

private:
    Expr *expr;
    ~Statement();
};

#endif //MAPLECOMPILER_STATEMENT_H
