#include <ir/instructions/WMemInstr.h>
#include <ir/instructions/OpInstr.h>
#include <ir/instructions/LoadConstInstr.h>
#include "TabDeclaration.h"

using std::vector;
using std::string;

TabDeclaration::TabDeclaration(Type type, unsigned long size, const string &name, const vector<Value *> &definition)
        : type(type), size(size), name(name), definition(definition) {}

const string &TabDeclaration::getName() const {
    return name;
}

string TabDeclaration::buildIR(CFG *cfg) {
    // FIXME Try to write everything in one instruction
    if (definition.empty()) return "";

    // Mem[i] = Mem + i * sizeof(type)
    // Mem[i] = Mem + byteDistance
    for (auto &&it = definition.begin(); it != definition.end(); it++) {
        long byteDistance = (it - definition.begin());
        switch (type) {
            case VOID:
                throw std::runtime_error("[TabDeclaration] Should not have type VOID");
            case CHAR:
                // Do nothing
                break;
            case INT32_T:
                byteDistance *= 4;
                break;
            case INT64_T:
                byteDistance *= 8;
                break;
        }

        auto index = cfg->createNewTmpVar(Type::INT64_T);
        cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, index, byteDistance));
        cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::ADD, index, name, index));

        auto cst = cfg->createNewTmpVar(Type::INT64_T);
        cfg->addIRInstr(new LoadConstInstr(cfg->currentBB, cst, (*it)->getType(), type));
        cfg->addIRInstr(new WMemInstr(cfg->currentBB, index, cst));
    }

    return "";
}

int TabDeclaration::getAllocationSize() {
    switch (type) {
        case VOID:
            // Should not append
            throw std::runtime_error("VarDeclaration with VOID type");
        case CHAR:
            return static_cast<int>(size);
        case INT32_T:
            return static_cast<int>(4 * size);
        case INT64_T:
            return static_cast<int>(8 * size);
    }
}

Type TabDeclaration::getType() const {
    return type;
}

unsigned long TabDeclaration::getSize() const {
    return size;
}
