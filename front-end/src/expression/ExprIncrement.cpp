#include <str2int.h>
#include <ostream>
#include <ir/instructions/LoadConstInstr.h>
#include <ir/instructions/WMemInstr.h>
#include <ir/instructions/OpInstr.h>
#include "ExprIncrement.h"

using namespace std;

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
            cerr << "Operator expected to be \"++\" or \"--\" but did not match." << endl;
            break;
    }

}

string ExprIncrement::buildIR(CFG *cfg) {
    string var = cfg->createNewTmpVar(Type::INT64_T);

    string var2 = cfg->createNewTmpVar(Type::INT64_T);
    auto loadConstant = new LoadConstInstr(cfg->currentBB, var2, 1);

    string var1 = leftValue->buildIR(cfg);

    auto opInstr = OpInstr::ADD;

    if (op == MINUS_MINUS) {
        opInstr = OpInstr::SUB;
    }


    IRInstr *addition = new OpInstr(cfg->currentBB, opInstr, var, var1, var2);

    auto *saveVar = new WMemInstr(cfg->currentBB, var1, var);

    cfg->addIRInstr(loadConstant);
    cfg->addIRInstr(addition);
    cfg->addIRInstr(saveVar);


    if (!isPostfix) {
        return var1;
    }

    // FIXME See to send value before addition


    return "<not_implemented>";
}
