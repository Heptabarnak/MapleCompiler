#include "SymbolTable.h"

using std::make_pair;

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

SymbolTable *SymbolTable::getFather() {
    return father;
}
