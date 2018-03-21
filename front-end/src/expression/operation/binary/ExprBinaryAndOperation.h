#ifndef ANTLR4CPP_FETCHER_EXPRBINARYANDOPERATION_H
#define ANTLR4CPP_FETCHER_EXPRBINARYANDOPERATION_H

#include "ExprBinaryOperation.h"

class ExprBinaryAndOperation : public ExprBinaryOperation {

public:
    ExprBinaryAndOperation(Expr *left, Expr *right);
};


#endif //ANTLR4CPP_FETCHER_EXPRBINARYANDOPERATION_H
