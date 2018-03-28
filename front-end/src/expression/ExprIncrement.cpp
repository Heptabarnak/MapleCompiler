#include <str2int.h>
#include <ir/instructions/LoadConstInstr.h>
#include <ir/instructions/AddInstr.h>
#include <ir/instructions/WMemInstr.h>
#include <ir/instructions/SubInstr.h>
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

string ExprIncrement::buildIR(CFG *cfg) {
    string var = cfg->createNewTmpVar(Type::INT64_T);
    auto *instr = new LoadConstInstr(cfg->currentBB, Type::INT64_T); //avec un 1, pas encore fonctionnel
    string var2 = leftValue->buildIR(cfg);
    IRInstr *instr2;
    switch (op) {
        case PLUS_PLUS:
            instr2 = new AddInstr(cfg->currentBB, Type::INT64_T); //pas encore fonctionnel
            break;
        case MINUS_MINUS:
            instr2 = new SubInstr(cfg->currentBB, Type::INT64_T); //pas encore fonctionnel
            break;
    }
    auto *instr3 = new WMemInstr(cfg->currentBB, Type::INT64_T);//pas encore fonctionnel
    cfg->currentBB->addIRInstr(instr);
    if (isPostfix) {
        cfg->currentBB->addIRInstr(instr3);
        cfg->currentBB->addIRInstr(instr2);
    } else {
        cfg->currentBB->addIRInstr(instr2);
        cfg->currentBB->addIRInstr(instr3);
    }
    return var;
}
