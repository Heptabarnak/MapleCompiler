#include <ir/instructions/LoadConstInstr.h>
#include "ExprValue.h"

using std::string;

ExprValue::ExprValue(Value *v, Type type)
        : value(v), Expr(type) {
}

bool ExprValue::isSimplifiable() {
    return true;
}

long ExprValue::simplify() {
    return value->getValue();
}

string ExprValue::buildIR(CFG *cfg) {
    string var = cfg->createNewTmpVar(value->getType());
    auto *instr = new LoadConstInstr(cfg->currentBB, var, value->getValue(), value->getType());
    cfg->addIRInstr(instr);
    return var;
}
