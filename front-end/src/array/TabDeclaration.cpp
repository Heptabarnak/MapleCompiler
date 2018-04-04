#include <ir/instructions/WMemInstr.h>
#include <ir/instructions/OpInstr.h>
#include <ir/instructions/LoadConstInstr.h>
#include <typeHelper.h>
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

    // Mem[i] = Mem + i * sizeof(type)
    // Mem[i] = Mem + byteDistance
    for (auto &&it = definition->begin(); it != definition->end(); it++) {
        long byteDistance = (it - definition->begin()) * getTypeAllocationSize(type);

        auto index = cfg->createNewTmpVar(Type::INT64_T);
        cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, index, byteDistance));
        cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::ADD, index, name, index));

        auto cst = cfg->createNewTmpVar(Type::INT64_T);
        cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, cst, (*it)->getValue(), type));
        cfg->addIRInstr(new WMemInstr(cfg->currentBB, index, cst));
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
