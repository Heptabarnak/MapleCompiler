#include "BlockFunction.h"

using std::string;
using std::vector;

BlockFunction::BlockFunction(const vector<Declaration *> &declarations,
                             const vector<Instruction *> &instructions,
                             SymbolTable *symbolTable)
        : declarations(declarations), instructions(instructions), symbolTable(symbolTable) {}

string BlockFunction::buildIR(CFG *cfg) {
    // Let's build a basic block for each ~instruction (not exactly)
    for (auto &&instruction : instructions) {
        instruction->buildIR(cfg);
    }
}
