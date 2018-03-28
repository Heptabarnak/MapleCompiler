#include <ir/instructions/LoadConstInstr.h>
#include "ExprValue.h"


ExprValue::ExprValue(Value *v)
        : value(v) {
}

bool ExprValue::isSimplifiable() {
    return true;
}

long ExprValue::simplify() {
    return value->getValue();
}

string ExprValue::buildIR(CFG *cfg) {
    string var = cfg->createNewTmpVar(value->getType());
    auto * instr = new LoadConstInstr(cfg->currentBB, value->getType()); //pas encore fonctionnel
    cfg->currentBB->addIRInstr(instr);
    return var;
}
