#include "SymbolTable.h"

using std::make_pair;

SymbolTable::SymbolTable(SymbolTable* father): father(father) {}

SymbolTable::~SymbolTable() {
    while(!children.empty()){
        delete children.back();
        children.pop_back();
    }

    while(!symbols.empty()){
        delete symbols.begin()->second;
        symbols.erase(symbols.begin());
    }


}

SymbolTable* SymbolTable::insert(string name, Symbol *symbol) {
    symbols.insert({name, symbol});
    return this;
}

Symbol* SymbolTable::lookup(string name) {
    auto it = symbols.find(name);
    if(it == symbols.end()){
        if( father != nullptr){
            return father->lookup(name);
        }
        else{
            return nullptr;
        }
    }
    else{
        return it->second;
    }
}