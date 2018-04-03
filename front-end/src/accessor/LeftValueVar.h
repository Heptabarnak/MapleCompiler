#ifndef MAPLECOMPILER_LEFTVALUEVAR_H
#define MAPLECOMPILER_LEFTVALUEVAR_H


#include <variable/VarAccessor.h>
#include "LeftValue.h"
#include <string>

class LeftValueVar : public LeftValue {

private:
    VarAccessor *varAccessor;

public:
    explicit LeftValueVar(VarAccessor *varAccessor);
    std::string getSymbolName() override;

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_LEFTVALUEVAR_H
