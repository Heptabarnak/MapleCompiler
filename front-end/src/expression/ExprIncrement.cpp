#include <str2int.h>
#include "ExprIncrement.h"

ExprIncrement::ExprIncrement(LeftValue *leftValue, std::string op_str, bool isPostfix)
        : leftValue(leftValue), isPostfix(isPostfix) {

    switch (str2int(op_str.c_str())) {
        case str2int("++"):
            op = PLUS_PLUS;
            break;
        case str2int("--"):
            op = MINUS_MINUS;
            break;
        default:
            // TODO Throw ERROR
            break;
    }

}