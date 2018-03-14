#ifndef ANTLR4CPP_FETCHER_STATEMENT_H
#define ANTLR4CPP_FETCHER_STATEMENT_H

#include <expression/Expr.h>
#include "Instruction.h"

class Statement : public Instruction {
public:
    Statement(Expr *e);

private:
    Expr *expr;
};

#endif //ANTLR4CPP_FETCHER_STATEMENT_H
