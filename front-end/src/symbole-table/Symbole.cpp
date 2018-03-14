#include "Symbole.h"

Symbole::Symbole(SymboleTable *table) : table(table){}

Symbole::~Symbole() {
    delete table;
}