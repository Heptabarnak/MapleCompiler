#include <str2int.h>
#include <ir/instructions/WMemInstr.h>
#include "ExprAffectation.h"

ExprAffectation::ExprAffectation(LeftValue *left, Expr *right, const std::string &op_str)
        : left(left), right(right) {

    switch (str2int(op_str.c_str())) {
        case str2int("="):
            op = EQUAL;
            break;
        case str2int("+="):
            op = PLUS_EQUAL;
            break;
        case str2int("-="):
            op = MINUS_EQUAL;
            break;
        case str2int("*="):
            op = MULT_EQUAL;
            break;
        case str2int("/="):
            op = DIV_EQUAL;
            break;
        case str2int("%="):
            op = MOD_EQUAL;
            break;
        case str2int("<<="):
            op = LEFT_SHIFT_EQUAL;
            break;
        case str2int(">>="):
            op = RIGHT_SHIFT_EQUAL;
            break;
        case str2int("&="):
            op = AND_EQUAL;
            break;
        case str2int("^="):
            op = XOR_EQUAL;
            break;
        case str2int("|="):
            op = OR_EQUAL;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}

string ExprAffectation::buildIR(CFG *cfg) {

    std::string value = right->buildIR(cfg);
    std::string dest = left->buildIR(cfg);

    auto instr = new WMemInstr(cfg->currentBB, dest, value);

    cfg->addIRInstr(instr);

    return value;
}
