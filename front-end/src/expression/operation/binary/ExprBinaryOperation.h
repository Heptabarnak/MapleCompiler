#ifndef MAPLECOMPILER_EXPRBINARYOPERATION_H
#define MAPLECOMPILER_EXPRBINARYOPERATION_H

#include <expression/operation/ExprOperation.h>

class ExprBinaryOperation : public ExprOperation {
protected:
    ExprBinaryOperation(Expr *left, Expr *right) : ExprOperation(left, right) {}

};


#endif //MAPLECOMPILER_EXPRBINARYOPERATION_H
