#include "Symbol.h"

Symbol::Symbol(SymbolTable *table, bool aff, bool r) : table(table), affectation(aff), read(r){}

Symbol::~Symbol() {
    delete table;
}