#ifndef MAPLECOMPILER_EXPRCOMMAOPERATION_H
#define MAPLECOMPILER_EXPRCOMMAOPERATION_H


#include "ExprOperation.h"

class ExprCommaOperation : ExprOperation{
private:

public:
    ExprCommaOperation(Expr *left, Expr *right, Type type);

private:
    std::string buildIR(CFG *cfg) override;

    bool isSimplifiable() override;

    long simplify() override;

};


#endif //MAPLECOMPILER_EXPRCOMMAOPERATION_H
