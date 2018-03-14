#include <str2int.h>
#include "ExprBinaryShiftOperation.h"

ExprBinaryShiftOperation::ExprBinaryShiftOperation(Expr *left, Expr *right, const string &op)
        : ExprBinaryOperation(left, right) {

    switch (str2int(op.c_str())) {
        case str2int("<<"):
            operation = LEFT;
            break;
        case str2int(">>"):
            operation = RIGHT;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}
