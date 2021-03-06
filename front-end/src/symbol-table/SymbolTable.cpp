#include "SymbolTable.h"
#include <iostream>
#include <variable/VarDeclaration.h>

using std::cout;
using std::endl;
using std::string;

SymbolTable::SymbolTable(SymbolTable *father) : father(father) {
    // Add to symbol table's children

    if (father != nullptr) {
        father->children.push_back(this);
    }
}

SymbolTable::~SymbolTable() {
    for (auto &child : children) {
        delete child;
    }
    children.clear();

    for (auto &symbol : symbols) {
        delete symbol.second;
        symbol.second = nullptr;
    }
}

SymbolTable *SymbolTable::insert(string name, Symbol *symbol) {
    symbols.insert({name, symbol});
    levels.insert({order, name});
    order++;

    // Offset handling
    offset += symbol->getDeclaration()->getAllocationSize();
    offsetTable.insert({name, offset});

    return this;
}

Symbol *SymbolTable::lookup(string name) {
    auto it = symbols.find(name);
    if (it == symbols.end()) {
        if (father != nullptr) {
            return father->lookup(name);
        }
        return nullptr;
    }
    return it->second;
}

void SymbolTable::staticAnalysis() {
    for (auto &&name : levels) {
        auto &&symbol = symbols.find(name.second)->second;

        // Skip main function
        if (name.second == "main") continue;

        if (!symbol->getRead()) {

            if (symbol->getAffectation()) {

                cout << "Warning : " << name.second << " was defined but not used." << endl;
            } else {
                cout << "Warning : " << name.second << " was declared but not defined nor used." << endl;
            }
        }
    }
    for (auto &&child  : children) {
        child->staticAnalysis();
    }
}


SymbolTable *SymbolTable::getFather() {
    return father;
}

string SymbolTable::createNewTmpVar(Type type) {
    string name = "!tmp" + std::to_string(order);

    auto declaration = new VarDeclaration(name, type);

    auto symbol = new Symbol(
            this,
            declaration
    ); // We are after static analysis, we can leave aff & read at default

    this->insert(name, symbol);

    return name;
}

long SymbolTable::getAllocationSize() {
    return offset;
}

long SymbolTable::getOffset(string &name) {
    auto item = offsetTable.find(name);

    if (item == offsetTable.end()) {
        return -1;
    }

    return item->second;
}
