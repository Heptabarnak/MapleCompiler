#ifndef MAPLECOMPILER_ACCESSORFUNCTION_H
#define MAPLECOMPILER_ACCESSORFUNCTION_H

#include <vector>
#include <expression/Expr.h>
#include <ir/BuildIR.h>
#include "FunctionDefinition.h"

class AccessorFunction : public BuildIR {

private:
    FunctionDefinition *declaration;
    std::vector<Expr *> arguments;

public:
    AccessorFunction(FunctionDefinition *declaration, std::vector<Expr *> const &arguments);

    std::string getSymbolName();

    string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_ACCESSORFUNCTION_H
