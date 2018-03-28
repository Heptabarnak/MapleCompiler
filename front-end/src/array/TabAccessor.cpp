#include "TabAccessor.h"

TabAccessor::TabAccessor(TabDeclaration *declaration, Expr *pos) : declaration(declaration), pos(pos) {}

std::string TabAccessor::getName() {
    return declaration->getName();
}

std::string TabAccessor::buildIR(CFG *cfg) {
    std::string varPos = pos->buildIR(cfg);

    // TODO Add new instruction to access an array

    return varPos;
}
