#include <str2int.h>
#include "ExprPrefixUnary.h"

ExprPrefixUnary::ExprPrefixUnary(Expr *expr, const string &op) : ExprUnary(expr) {

    switch (str2int(op.c_str())) {
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

bool ExprPrefixUnary::isSimplifiable() {
    return expr->isSimplifiable();
}

long ExprPrefixUnary::simplify() {
    switch (prefixOp) {
        case PLUS:
            return +expr->simplify();
        case MINUS:
            return -expr->simplify();
        case NOT:
            return !expr->simplify();
        case BITWISE_NOT:
            return ~expr->simplify();
    }
}
