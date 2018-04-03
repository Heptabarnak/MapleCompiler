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

class SymbolTable;

class FunctionDefinition : public Declaration {

private:
    BlockFunction *block;
    Type type;
    std::vector<FunctionParam *> *params;
    std::string name;
    SymbolTable *symbolTable;

public:
    FunctionDefinition(Type type, const std::string &name);

    std::string getSymbolName();

    Type getType() const;

    SymbolTable *getSymbolTable() const;

    void setSymbolTable(SymbolTable *symbolTable);

    void setBlockFunction(BlockFunction *block);

    void setArguments(std::vector<FunctionParam *> *params);

    BlockFunction *getBlock() const;

    std::string buildIR(CFG *cfg);

    int getAllocationSize() override;

    std::vector<FunctionParam *> *getParams();
};


#endif //MAPLECOMPILER_FUNCTIONDEFINITION_H
