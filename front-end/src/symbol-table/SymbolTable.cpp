#include "SymbolTable.h"
#include <iostream>

using std::make_pair;
using namespace std;

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

void SymbolTable::staticAnalysis() {
    for (auto &&symbol : symbols) {
        if (!symbol.second->getRead()){
            if(!symbol.second->getAffectation()){
                cout << "Warning : " << symbol.first << "is not used." << endl;
            } else {
                cout << "Warning : " << symbol.first << "was declared but not read." << endl;
            }
        }
    }
}



SymbolTable *SymbolTable::getFather() {
    return father;
}
