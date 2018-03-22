#include "BlockFunction.h"

BlockFunction::BlockFunction(const vector<Declaration *> &declarations, const vector<Instruction *> &instructions,
                             SymbolTable *symbolTable) : declarations(declarations), instructions(instructions),
                                                         symbolTable(symbolTable) {}
