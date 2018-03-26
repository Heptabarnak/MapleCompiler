#include <str2int.h>
#include <iostream>
#include "ExprMultiplicativeOperation.h"

using std::cerr;
using std::endl;

ExprMultiplicativeOperation::ExprMultiplicativeOperation(Expr *left, Expr *right, const string &op)
        : ExprOperation(left, right) {

    switch (str2int(op.c_str())) {
        case str2int("*"):
            operation = MULT;
            break;
        case str2int("/"):
            operation = DIV;
            break;
        case str2int("%"):
            operation = MOD;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}

long ExprMultiplicativeOperation::simplify() {
    switch (operation) {
        case MULT:
            return leftExpr->simplify() * rightExpr->simplify();
        case DIV:
            if (rightExpr->simplify() != 0) {
                return leftExpr->simplify() / rightExpr->simplify();
            }
            else {
                cerr << "Division by 0 is forbidden" << endl;
                throw std::runtime_error("Forbidden operation : division by zero");
            }
        case MOD:
            return leftExpr->simplify() % rightExpr->simplify();
    }
}
