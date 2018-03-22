#ifndef MAPLECOMPILER_EXPRBINARYANDOPERATION_H
#define MAPLECOMPILER_EXPRBINARYANDOPERATION_H

#include "ExprBinaryOperation.h"

class ExprBinaryAndOperation : public ExprBinaryOperation {

public:
    ExprBinaryAndOperation(Expr *left, Expr *right);

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPRBINARYANDOPERATION_H
