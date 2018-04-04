#include <str2int.h>
#include <ostream>
#include <stdexcept>
#include <ir/instructions/LoadConstInstr.h>
#include <ir/instructions/WMemInstr.h>
#include <ir/instructions/OpInstr.h>
#include <ir/instructions/IncrInstr.h>
#include "ExprIncrement.h"

using std::string;
using std::cerr;
using std::endl;

ExprIncrement::ExprIncrement(LeftValueAccessor *leftValue, string op_str, bool isPostfix)
        : leftValue(leftValue), isPostfix(isPostfix) {

    switch (str2int(op_str.c_str())) {
        case str2int("++"):
            op = PLUS_PLUS;
            break;
        case str2int("--"):
            op = MINUS_MINUS;
            break;
        default:
            cerr << "Operator expected to be \"++\" or \"--\" but did not match." << endl;
            throw std::runtime_error("[ExprIncrement] Unexpected operator");
    }

}

string ExprIncrement::buildIR(CFG *cfg) {
    string var = cfg->createNewTmpVar(Type::INT64_T);
    string var1 = leftValue->buildIR(cfg);

    auto opInstr = IncrInstr::PLUS;

    if (op == MINUS_MINUS) {
        opInstr = IncrInstr::MINUS;
    }

    cfg->addIRInstr(new IncrInstr(cfg->currentBB, opInstr, var, var1, isPostfix));

    return var;
}
