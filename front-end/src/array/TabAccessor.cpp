#include <ir/instructions/OpInstr.h>
#include <ir/instructions/LoadConstInstr.h>
#include <ir/instructions/RMemInstr.h>
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


    // Mem[i] == Mem + i * sizeof(type)

    unsigned long sizeofTab = declaration->getAllocationSize() / declaration->getSize();

    auto unitSize = cfg->createNewTmpVar(Type::INT64_T);
    cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, unitSize, sizeofTab));

    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::MULT, varPos, varPos, unitSize));
    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::ADD, varPos, varPos, declaration->getName()));

    cfg->addIRInstr(new RMemInstr(cfg->currentBB, value, varPos));

    return value;
}
