#include <str2int.h>
#include "ExprPrefixUnary.h"

ExprPrefixUnary::ExprPrefixUnary(Expr *expr, const string &op) : ExprUnary(expr) {


    switch (str2int(op.c_str())) {
        case str2int("++"):
            prefixOp = PLUS_PLUS;
            break;
        case str2int("--"):
            prefixOp = MINUS_MINUS;
            break;
        case str2int("+"):
            prefixOp = PLUS;
            break;
        case str2int("-"):
            prefixOp = MINUS;
            break;
        case str2int("!"):
            prefixOp = NOT;
            break;
        case str2int("~"):
            prefixOp = BITWISE_NOT;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}
