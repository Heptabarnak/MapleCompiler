#ifndef MAPLECOMPILER_EXPRAFFECTATION_H
#define MAPLECOMPILER_EXPRAFFECTATION_H


#include <expression/Expr.h>
#include <expression/ExprAccessor.h>
#include <string>
#include <accessor/LeftValue.h>


class ExprAffectation : public Expr {
    enum OP {
        EQUAL,
        PLUS_EQUAL,
        MINUS_EQUAL,
        MULT_EQUAL,
        DIV_EQUAL,
        MOD_EQUAL,
        LEFT_SHIFT_EQUAL,
        RIGHT_SHIFT_EQUAL,
        AND_EQUAL,
        XOR_EQUAL,
        OR_EQUAL
    };


    LeftValue *left;
    Expr *right;

    OP op;

public:

    ExprAffectation(LeftValue *left, Expr *right, const std::string &op);
};


#endif //MAPLECOMPILER_EXPRAFFECTATION_H
