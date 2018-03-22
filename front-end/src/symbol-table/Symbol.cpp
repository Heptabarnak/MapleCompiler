#include "Symbol.h"

Symbol::Symbol(SymbolTable *table, Declaration * dec, bool aff, bool r) : table(table), declaration(dec), affectation(aff), read(r){}

Symbol::~Symbol() {
    delete table;
}

Declaration *Symbol::getDeclaration() const {
    return declaration;
}
