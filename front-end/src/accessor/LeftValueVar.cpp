

#include "LeftValueVar.h"

LeftValueVar::LeftValueVar(VarAccessor *varAccessor) : varAccessor(varAccessor) {}

std::string LeftValueVar::getSymbolName() {
    return varAccessor->getName();
}

string LeftValueVar::buildIR(CFG *cfg) {
    return varAccessor->buildIR(cfg);
}

