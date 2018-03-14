#ifndef ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVEOPERATION_H
#define ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVEOPERATION_H

#include <string>
#include "ExprOperation.h"

using std::string;

class ExprMultiplicativeOperation : public ExprOperation {
private:
    enum MultiplicativeOperation {
        MULT,
        DIV,
        MOD
    };

    MultiplicativeOperation operation;

public:
    ExprMultiplicativeOperation(Expr *left, Expr *right, const string &op);
};


#endif //ANTLR4CPP_FETCHER_EXPRMULTIPLICATIVEOPERATION_H
