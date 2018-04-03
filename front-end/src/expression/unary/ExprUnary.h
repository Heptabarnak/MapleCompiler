#ifndef MAPLECOMPILER_EXPRUNARY_H
#define MAPLECOMPILER_EXPRUNARY_H

#include <expression/Expr.h>

class ExprUnary : public Expr {
protected:
    Expr *expr;

    explicit ExprUnary(Expr *expr) : expr(expr) {}
};


#endif //MAPLECOMPILER_EXPRUNARY_H
