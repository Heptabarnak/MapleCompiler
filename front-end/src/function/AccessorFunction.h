#ifndef MAPLECOMPILER_ACCESSORFUNCTION_H
#define MAPLECOMPILER_ACCESSORFUNCTION_H

#include <vector>
#include <expression/Expr.h>
#include <ir/BuildIR.h>
#include <accessor/Accessor.h>
#include "FunctionDefinition.h"

class AccessorFunction : public Accessor {

private:
    FunctionDefinition *declaration;
    std::vector<Expr *> *arguments;

public:
    Type getType() override;

    AccessorFunction(FunctionDefinition *declaration, std::vector<Expr *> *arguments);

    std::string getSymbolName();

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_ACCESSORFUNCTION_H
