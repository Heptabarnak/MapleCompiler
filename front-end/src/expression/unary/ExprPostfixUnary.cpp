#include <str2int.h>
#include "ExprPostfixUnary.h"

ExprPostfixUnary::ExprPostfixUnary(Expr *expr, const string &op) : ExprUnary(expr) {
    switch (str2int(op.c_str())) {
        case str2int("++"):
            postfixOp = PLUS_PLUS;
            break;
        case str2int("--"):
            postfixOp = MINUS_MINUS;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}
