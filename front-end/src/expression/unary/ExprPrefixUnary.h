#ifndef ANTLR4CPP_FETCHER_EXPRPREFIXUNARY_H
#define ANTLR4CPP_FETCHER_EXPRPREFIXUNARY_H

#include <string>
#include "ExprUnary.h"

using std::string;

class ExprPrefixUnary : public ExprUnary {
private:
    enum PrefixOperation {
        PLUS_PLUS,
        MINUS_MINUS,
        PLUS,
        MINUS,
        NOT,
        BITWISE_NOT
    };

    PrefixOperation prefixOp;

public:
    ExprPrefixUnary(Expr *expr, const string &op);

};


#endif //ANTLR4CPP_FETCHER_EXPRPREFIXUNARY_H
