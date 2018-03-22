#ifndef MAPLECOMPILER_EXPRANDOPERATION_H
#define MAPLECOMPILER_EXPRANDOPERATION_H


#include "ExprOperation.h"

class ExprAndOperation : public ExprOperation {

public:
    ExprAndOperation(Expr * left, Expr * right);

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPRANDOPERATION_H