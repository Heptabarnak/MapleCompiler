#include <str2int.h>
#include "ExprMultiplicative.h"

ExprMultiplicative::ExprMultiplicative(Expr *left, Expr *right, const std::string &op_str)
        : left(left), right(right) {

    switch (str2int(op_str.c_str())) {
        case str2int("*"):
            op = MULT;
            break;
        case str2int("/"):
            op = DIV;
            break;
        case str2int("%"):
            op = MOD;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}


int ExprMultiplicative::eval() {


    return 0;
}
