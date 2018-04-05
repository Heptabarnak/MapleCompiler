#include <str2int.h>
#include <ostream>
#include <stdexcept>
#include <ir/instructions/OpInstr.h>
#include <ir/instructions/WMemInstr.h>
#include <ir/instructions/WMemArrayInstr.h>
#include <variable/VarAccessor.h>
#include <array/TabAccessor.h>
#include "ExprAffectation.h"

using std::cerr;
using std::string;
using std::endl;

ExprAffectation::ExprAffectation(LeftValueAccessor *left, Expr *right, const string &op_str, Type type)
        : left(left), right(right), Expr(type) {

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
            cerr << "Operator expected to be \"=\", \"+=\", \"-=\", \"*=\", \"/=\", \"%=\", \"<<=\", \">>=\",";
            cerr << " \"&=\", \"^=\" or \"|=\" but did not match." << endl;
            throw std::runtime_error("[ExprAffectation] Unexpected operator");
    }
}

string ExprAffectation::buildIR(CFG *cfg) {

    string value = right->buildIR(cfg);
    string dest = left->buildIR(cfg);

    if (op != EQUAL) {
        // We save the new value
        OpInstr::OpType type;
        switch (op) {
            case PLUS_EQUAL:
                type = OpInstr::ADD;
                break;
            case MINUS_EQUAL:
                type = OpInstr::SUB;
                break;
            case MULT_EQUAL:
                type = OpInstr::MULT;
                break;
            case DIV_EQUAL:
                type = OpInstr::DIV;
                break;
            case MOD_EQUAL:
                type = OpInstr::MOD;
                break;
            case LEFT_SHIFT_EQUAL:
                type = OpInstr::SHIFT_LEFT;
                break;
            case RIGHT_SHIFT_EQUAL:
                type = OpInstr::SHIFT_RIGHT;
                break;
            case AND_EQUAL:
                type = OpInstr::AND;
                break;
            case XOR_EQUAL:
                type = OpInstr::XOR;
                break;
            case OR_EQUAL:
                type = OpInstr::OR;
                break;
        }

        cfg->addIRInstr(new OpInstr(cfg->currentBB, type, value, dest, value, getType(), left->getType(), right->getType() ));
    }

    if (auto leftVar = dynamic_cast<VarAccessor *>(left)) {
        cfg->addIRInstr(new WMemInstr(cfg->currentBB, dest, value, left->getType()));
    } else if (auto leftTab = dynamic_cast<TabAccessor *>(left)) {
        string pos = leftTab->getPos()->buildIR(cfg);

        cfg->addIRInstr(
                new WMemArrayInstr(cfg->currentBB, value, leftTab->getDeclaration()->getName(), pos,
                                   leftTab->getDeclaration()->getType()));
    }
    return value;
}
