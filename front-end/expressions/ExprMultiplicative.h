#ifndef ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVE_H
#define ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVE_H

#include <expressions/Expr.h>
#include <string>


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

class ExprMultiplicative : public Expr {

    Expr *left;
    Expr *right;

    OP op;

public:

    ExprMultiplicative(Expr *left, Expr *right, const std::string &op);

    int eval() override;
};

#endif //ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVE_H
