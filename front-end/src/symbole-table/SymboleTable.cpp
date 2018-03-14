#include "SymboleTable.h"

using std::make_pair;

SymboleTable::SymboleTable(SymboleTable* father): father(father) {}

SymboleTable::~SymboleTable() {
    while(!children.empty()){
        delete children.back();
        children.pop_back();
    }

    while(!symbols.empty()){
        delete symbols.begin()->second;
        symbols.erase(symbols.begin());
    }


}

SymboleTable* SymboleTable::insert(string name, Symbole *symbole) {
    symbols.insert({name, symbole});
    return this;
}

Symbole* SymboleTable::lookup(string name) {
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