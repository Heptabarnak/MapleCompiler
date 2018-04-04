#include <ir/instructions/OpInstr.h>
#include <ir/instructions/LoadConstInstr.h>
#include <ir/instructions/RMemInstr.h>
#include <typeHelper.h>
#include "TabAccessor.h"

using std::string;

TabAccessor::TabAccessor(TabDeclaration *declaration, Expr *pos) : declaration(declaration), pos(pos) {}

string TabAccessor::getName() {
    return declaration->getName();
}

string TabAccessor::buildIR(CFG *cfg) {
    string value = cfg->createNewTmpVar(declaration->getType());
    string arrayName = declaration->getName();
    string varPos = pos->buildIR(cfg);


    // Mem[i] == Mem + i * sizeof(type)

    int typeSize = getTypeAllocationSize(declaration->getType());

    auto unitSize = cfg->createNewTmpVar(Type::INT64_T);
    cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, unitSize, typeSize));

    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::MULT, varPos, varPos, unitSize));
    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::ADD, varPos, varPos, arrayName));

    cfg->addIRInstr(new RMemInstr(cfg->currentBB, value, varPos));

    return value;
}
