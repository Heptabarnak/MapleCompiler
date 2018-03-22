#include "Start.h"

Start::Start(const vector<Declaration *> &declarations, const SymbolTable &globalSymbolTable)
        : declarations(declarations), globalSymbolTable(globalSymbolTable) {}
