#ifndef ANTLR4CPP_FETCHER_EXPRPOSTFIXUNARY_H
#define ANTLR4CPP_FETCHER_EXPRPOSTFIXUNARY_H


#include <string>
#include "ExprUnary.h"

using std::string;

class ExprPostfixUnary : public ExprUnary {
private:
    enum PostfixOperation {
        PLUS_PLUS,
        MINUS_MINUS
    };

    PostfixOperation postfixOp;

public:
    ExprPostfixUnary(Expr *expr, const string &op);

};


#endif //ANTLR4CPP_FETCHER_EXPRPOSTFIXUNARY_H
