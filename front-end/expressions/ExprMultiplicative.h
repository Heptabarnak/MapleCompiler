#ifndef ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVE_H
#define ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVE_H

#include <expressions/Expr.h>
#include <string>


class ExprMultiplicative : public Expr {

    enum OP {
        MULT,
        DIV,
        MOD
    };

    Expr *left;
    Expr *right;

    OP op;

public:

    ExprMultiplicative(Expr *left, Expr *right, const std::string &op);

    int eval() override;
};

#endif //ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVE_H
