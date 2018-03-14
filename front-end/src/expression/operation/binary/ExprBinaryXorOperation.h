#ifndef ANTLR4CPP_FETCHER_EXPRBINARYXOROPERATION_H
#define ANTLR4CPP_FETCHER_EXPRBINARYXOROPERATION_H

#include "ExprBinaryOperation.h"

class ExprBinaryXorOperation : public ExprBinaryOperation {

public:
    ExprBinaryXorOperation(Expr *left, Expr *right);
};

#endif //ANTLR4CPP_FETCHER_EXPRBINARYXOROPERATION_H
