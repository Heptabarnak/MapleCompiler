//
// Created by Ordinateur on 03/04/2018.
//

#ifndef MAPLECOMPILER_EXPRCOMMAOPERATION_H
#define MAPLECOMPILER_EXPRCOMMAOPERATION_H


#include "ExprOperation.h"

class ExprCommaOperation : ExprOperation{
private:

public:
    ExprCommaOperation(Expr *left, Expr *right);

private:
    std::string buildIR(CFG *cfg) override;

    bool isSimplifiable() override;

    long simplify() override;

};


#endif //MAPLECOMPILER_EXPRCOMMAOPERATION_H
