#ifndef ANTLR4CPP_FETCHER_EXPRBINARYOPERATION_H
#define ANTLR4CPP_FETCHER_EXPRBINARYOPERATION_H

#include <expression/operation/ExprOperation.h>

class ExprBinaryOperation : public ExprOperation {
protected:
    ExprBinaryOperation(Expr *left, Expr *right) : ExprOperation(left, right) {}

};


#endif //ANTLR4CPP_FETCHER_EXPRBINARYOPERATION_H
