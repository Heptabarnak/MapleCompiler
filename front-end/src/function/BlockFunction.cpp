#include "BlockFunction.h"

BlockFunction::BlockFunction(const list<Declaration *> &declarations, const list<Instruction *> &instructions,
                             SymbolTable *symbolTable) : declarations(declarations), instructions(instructions),
                                                         symbolTable(symbolTable) {}
