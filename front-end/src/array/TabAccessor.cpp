#include <ir/instructions/RMemArrayInstr.h>
#include "TabAccessor.h"

using std::string;

TabAccessor::TabAccessor(TabDeclaration *declaration, Expr *pos) : declaration(declaration), pos(pos) {}

string TabAccessor::buildIR(CFG *cfg) {
    string value = cfg->createNewTmpVar(declaration->getType());
    if (pos == nullptr) {
        return declaration->getName();
    }
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

string TabAccessor::getSymbolName() {
    return declaration->getName();
}

Type TabAccessor::getType() {
    return declaration->getType();
}
