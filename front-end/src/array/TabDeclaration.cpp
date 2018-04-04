#include <ir/instructions/LoadConstInstr.h>
#include <typeHelper.h>
#include <ir/instructions/WMemArrayInstr.h>
#include "TabDeclaration.h"

using std::vector;
using std::string;

TabDeclaration::TabDeclaration(Type type, unsigned long size, const string &name, vector<Value *> *definition)
        : type(type), size(size), name(name), definition(definition) {}

const string &TabDeclaration::getName() const {
    return name;
}

string TabDeclaration::buildIR(CFG *cfg) {
    // FIXME Try to write everything in one instruction
    if (definition->empty()) return "";

    for (auto &&it = definition->begin(); it != definition->end(); it++) {
        auto index = cfg->createNewTmpVar(Type::INT64_T);
        cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, index, it - definition->begin()));

        auto cst = cfg->createNewTmpVar(Type::INT64_T);
        cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, cst, (*it)->getValue(), type));

        cfg->addIRInstr(new WMemArrayInstr(cfg->currentBB, cst, name, index, type));
    }

    return "";
}

int TabDeclaration::getAllocationSize() {
    return static_cast<int>(getTypeAllocationSize(type) * size);
}

Type TabDeclaration::getType() const {
    return type;
}

unsigned long TabDeclaration::getSize() const {
    return size;
}

vector<Value *> *TabDeclaration::getDefinition() const {
    return definition;
}
