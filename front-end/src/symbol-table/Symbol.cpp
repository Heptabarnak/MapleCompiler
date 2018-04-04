#include "Symbol.h"

Symbol::Symbol(SymbolTable *table, Declaration *dec, bool aff, bool r)
        : table(table), declaration(dec), affectation(aff), read(r) {}

Symbol::~Symbol() {
    delete table;
}

Declaration *Symbol::getDeclaration() const {
    return declaration;
}

void Symbol::doRead() {
    read = true;
}

void Symbol::doAffectation() {
    affectation = true;
}

bool Symbol::getAffectation() {
    return affectation;
}

bool Symbol::getRead() {
    return read;
}

void Symbol::setDeclaration(Declaration *dec) {
    declaration = dec;
}
