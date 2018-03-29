#include <ir/instructions/RMemArrayInstr.h>
#include "TabAccessor.h"

using std::string;

TabAccessor::TabAccessor(TabDeclaration *declaration, Expr *pos) : declaration(declaration), pos(pos) {}

string TabAccessor::getName() {
    return declaration->getName();
}

string TabAccessor::buildIR(CFG *cfg) {
    string value = cfg->createNewTmpVar(Type::INT64_T);
    string arrayName = declaration->getName();
    string varPos = pos->buildIR(cfg);

    cfg->addIRInstr(new RMemArrayInstr(cfg->currentBB, value, arrayName, varPos));

    return value;
}
