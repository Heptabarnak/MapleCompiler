#include <ir/instructions/RMemArrayInstr.h>
#include "TabAccessor.h"

TabAccessor::TabAccessor(TabDeclaration *declaration, Expr *pos) : declaration(declaration), pos(pos) {}

std::string TabAccessor::getName() {
    return declaration->getName();
}

std::string TabAccessor::buildIR(CFG *cfg) {
    std::string value = cfg->createNewTmpVar(Type::INT64_T);
    std::string arrayName = declaration->getName();
    std::string varPos = pos->buildIR(cfg);

    cfg->addIRInstr(new RMemArrayInstr(cfg->currentBB, value, arrayName, varPos));

    return value;
}
