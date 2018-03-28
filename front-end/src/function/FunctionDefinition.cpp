#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(Type type, const string &name, SymbolTable *symbolTable)
        : type(type), name(name), symbolTable(symbolTable) {}

std::string FunctionDefinition::getSymbolName() {
    return name;
}

void FunctionDefinition::setBlockFunction(BlockFunction *block) {
    this->block = block;
}

void FunctionDefinition::setArguments(const vector<FunctionParam *> &params) {
    this->params = params;
}

std::string FunctionDefinition::buildIR(CFG *cfg) {

    // I don't know if I need to do something with arguments?

    // Create instructions
    block->buildIR(cfg);
}

SymbolTable *FunctionDefinition::getSymbolTable() const {
    return symbolTable;
}

Type FunctionDefinition::getType() const {
    return type;
}
