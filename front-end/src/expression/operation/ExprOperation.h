#ifndef MAPLECOMPILER_EXPROPERATION_H
#define MAPLECOMPILER_EXPROPERATION_H

#include <expression/Expr.h>

class ExprOperation : public Expr {
protected:
    Expr *leftExpr;
    Expr *rightExpr;

protected:
    ExprOperation(Expr *left, Expr *right) : leftExpr(left), rightExpr(right) {}

public:
    bool isSimplifiable() override {
        return leftExpr->isSimplifiable() && rightExpr->isSimplifiable();
    }

};


#endif //MAPLECOMPILER_EXPROPERATION_H
