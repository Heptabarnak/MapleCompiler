#include "VarAccessor.h"

using std::string;

VarAccessor::VarAccessor(VarDeclaration *dec) : declaration(dec) {}

string VarAccessor::getName() {
    return declaration->getName();
}

string VarAccessor::buildIR(CFG *cfg) {
    return declaration->getName();
}

