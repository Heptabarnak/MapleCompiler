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

using std::string;
using std::vector;

class FunctionDefinition : public Declaration, public BuildIR {

private:
    BlockFunction *block;
    Type type;
    vector<FunctionParam *> params;
    string name;
    SymbolTable *symbolTable;

public:
    FunctionDefinition(Type type, const string &name, SymbolTable *symbolTable);

    string getSymbolName();

    SymbolTable *getSymbolTable() const;

    void setBlockFunction(BlockFunction *block);

    void setArguments(const vector<FunctionParam *> &params);

    std::string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_FUNCTIONDEFINITION_H
