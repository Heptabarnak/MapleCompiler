#include <iostream>
#include "FunctionDefinition.h"

using std::string;
using std::vector;

FunctionDefinition::FunctionDefinition(Type type, const string &name)
        : type(type), name(name), symbolTable(nullptr) {}

string FunctionDefinition::getSymbolName() {
    return name;
}

void FunctionDefinition::setBlockFunction(BlockFunction *block) {
    this->block = block;
}

void FunctionDefinition::setArguments(vector<FunctionParam *> *params) {
    this->params = params;
}

string FunctionDefinition::buildIR(CFG *cfg) {
    return block->buildIR(cfg);
}

SymbolTable *FunctionDefinition::getSymbolTable() const {
    return symbolTable;
}

Type FunctionDefinition::getType() const {
    return type;
}

int FunctionDefinition::getAllocationSize() {
    return 0;
}

void FunctionDefinition::setSymbolTable(SymbolTable *symbolTable) {
    this->symbolTable = symbolTable;
}

std::vector<FunctionParam *>* FunctionDefinition::getParams() {
    return params;
}

BlockFunction *FunctionDefinition::getBlock() const {
    return block;
}
