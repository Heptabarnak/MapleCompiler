#include "../expressions/Expr.h"

#ifndef ANTLR4CPP_FETCHER_STATEMENT_H
#define ANTLR4CPP_FETCHER_STATEMENT_H

class Statement{
public:
    Statement(Expr * e);
private:
    Expr * expr;
};

#endif //ANTLR4CPP_FETCHER_STATEMENT_H
