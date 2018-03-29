

#include "VarAccessor.h"

VarAccessor::VarAccessor(VarDeclaration *dec) : declaration(dec) {}

std::string VarAccessor::getName() {
    return declaration->getName();
}

string VarAccessor::buildIR(CFG *cfg) {
    return declaration->getName();
}
