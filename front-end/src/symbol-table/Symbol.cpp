#include "Symbol.h"

Symbol::Symbol(SymbolTable *table) : table(table){}

Symbol::~Symbol() {
    delete table;
}