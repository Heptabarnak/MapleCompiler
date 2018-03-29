#include <ir/instructions/RMemInstr.h>
#include "TabDeclaration.h"

TabDeclaration::TabDeclaration(Type type, unsigned long size, const string &name, const vector<Value *> &definition)
        : type(type), size(size), name(name), definition(definition) {}

const string &TabDeclaration::getName() const {
    return name;
}

string TabDeclaration::buildIR(CFG *cfg) {
    std::string value = cfg->createNewTmpVar(Type::INT64_T);
    std::string arrayName = name;

    cfg->addIRInstr(new RMemInstr(cfg->currentBB, value, name ));

    return value;
}
