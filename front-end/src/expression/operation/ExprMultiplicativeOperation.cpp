#include <str2int.h>
#include "ExprMultiplicativeOperation.h"

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
