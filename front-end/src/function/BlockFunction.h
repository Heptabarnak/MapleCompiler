#ifndef MAPLECOMPILER_BLOCKFUNCTION_H
#define MAPLECOMPILER_BLOCKFUNCTION_H


#include <vector>
#include <declaration/Declaration.h>
#include <control-structure/Instruction.h>
#include <symbol-table/SymbolTable.h>
#include <ir/BuildIR.h>

class BlockFunction : public BuildIR {

private:
    std::vector<Declaration *> declarations;
    std::vector<Instruction *> instructions;
    SymbolTable *symbolTable;

public:
    BlockFunction(const std::vector<Declaration *> &declarations, const std::vector<Instruction *> &instructions,
                  SymbolTable *symbolTable);

    std::string buildIR(CFG *cfg) override;

};


#endif //MAPLECOMPILER_BLOCKFUNCTION_H
