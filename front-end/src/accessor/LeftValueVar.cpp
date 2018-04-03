#include "LeftValueVar.h"

using std::string;

LeftValueVar::LeftValueVar(VarAccessor *varAccessor) : varAccessor(varAccessor) {}

string LeftValueVar::getSymbolName() {
    return varAccessor->getName();
}

string LeftValueVar::buildIR(CFG *cfg) {
    return varAccessor->buildIR(cfg);
}

