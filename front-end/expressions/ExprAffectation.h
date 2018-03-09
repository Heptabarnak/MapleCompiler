#ifndef ANTLR4CPP_FETCHER_EXPRAFFECTATION_H
#define ANTLR4CPP_FETCHER_EXPRAFFECTATION_H


#include <expressions/Expr.h>
#include <accessor/Accessor.h>
#include <string>




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


    Accessor *left;
    Expr *right;

    OP op;

public:

    ExprAffectation(Accessor *left, Expr *right, const std::string &op);

    int eval() override;
};


#endif //ANTLR4CPP_FETCHER_EXPRAFFECTATION_H
