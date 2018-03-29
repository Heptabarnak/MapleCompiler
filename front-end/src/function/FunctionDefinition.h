#ifndef MAPLECOMPILER_FUNCTIONDEFINITION_H
#define MAPLECOMPILER_FUNCTIONDEFINITION_H


#include <string>
#include <vector>
#include <token/Type.h>
#include <declaration/Declaration.h>
#include <ir/BuildIR.h>
#include <ir/CFG.h>
#include "BlockFunction.h"
#include "FunctionParam.h"

class FunctionDefinition : public Declaration, public BuildIR {

private:
    BlockFunction *block;
    Type type;
    std::vector<FunctionParam *> params;
    std::string name;
    SymbolTable *symbolTable;

public:
    FunctionDefinition(Type type, const std::string &name, SymbolTable *symbolTable);

    std::string getSymbolName();

    Type getType() const;

    SymbolTable *getSymbolTable() const;

    void setBlockFunction(BlockFunction *block);

    void setArguments(const std::vector<FunctionParam *> &params);

    std::string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_FUNCTIONDEFINITION_H
