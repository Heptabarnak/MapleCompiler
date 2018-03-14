#ifndef ANTLR4CPP_FETCHER_EXPRBINARYOROPERATION_H
#define ANTLR4CPP_FETCHER_EXPRBINARYOROPERATION_H

#include "ExprBinaryOperation.h"

class ExprBinaryOrOperation : public ExprBinaryOperation {

public:
    ExprBinaryOrOperation(Expr *left, Expr *right);
};

#endif //ANTLR4CPP_FETCHER_EXPRBINARYOROPERATION_H
