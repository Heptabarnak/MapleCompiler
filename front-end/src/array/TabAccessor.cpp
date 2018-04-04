#include <ir/instructions/RMemArrayInstr.h>
#include "TabAccessor.h"

using std::string;

TabAccessor::TabAccessor(TabDeclaration *declaration, Expr *pos) : declaration(declaration), pos(pos) {}

string TabAccessor::getName() {
    return declaration->getName();
}

string TabAccessor::buildIR(CFG *cfg) {
    string value = cfg->createNewTmpVar(declaration->getType());
    string varPos = pos->buildIR(cfg);

    cfg->addIRInstr(new RMemArrayInstr(cfg->currentBB, value, declaration->getName(), varPos, declaration->getType()));

    return value;
}

TabDeclaration *TabAccessor::getDeclaration() const {
    return declaration;
}

Expr *TabAccessor::getPos() const {
    return pos;
}
