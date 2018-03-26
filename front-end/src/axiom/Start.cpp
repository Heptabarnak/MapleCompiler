#include "Start.h"

Start::Start(const vector<Declaration *> &declarations, SymbolTable *globalSymbolTable)
        : declarations(declarations), globalSymbolTable(globalSymbolTable) {}

SymbolTable *Start::getGlobalSymbolTable() const {
    return globalSymbolTable;
}
