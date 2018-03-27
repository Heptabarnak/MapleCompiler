#ifndef MAPLECOMPILER_BLOCKFUNCTION_H
#define MAPLECOMPILER_BLOCKFUNCTION_H


#include <vector>
#include <declaration/Declaration.h>
#include <control-structure/Instruction.h>
#include <symbol-table/SymbolTable.h>
#include <ir/BuildIR.h>

using std::vector;

class BlockFunction : public BuildIR {

private:
    vector<Declaration *> declarations;
    vector<Instruction *> instructions;
    SymbolTable *symbolTable;

public:
    BlockFunction(const vector<Declaration *> &declarations, const vector<Instruction *> &instructions,
                  SymbolTable *symbolTable);

    string buildIR(CFG *cfg) override;

};


#endif //MAPLECOMPILER_BLOCKFUNCTION_H
