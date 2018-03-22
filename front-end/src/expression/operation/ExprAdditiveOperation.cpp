#include <str2int.h>
#include "ExprAdditiveOperation.h"

ExprAdditiveOperation::ExprAdditiveOperation(Expr *left, Expr *right, const string &op) : ExprOperation(left, right) {

    switch (str2int(op.c_str())) {
        case str2int("+"):
            operation = PLUS;
            break;
        case str2int("-"):
            operation = MINUS;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}

long ExprAdditiveOperation::simplify() {
    switch (operation) {
        case PLUS:
            return leftExpr->simplify() + rightExpr->simplify();
        case MINUS:
            return leftExpr->simplify() - rightExpr->simplify();
    }
}
