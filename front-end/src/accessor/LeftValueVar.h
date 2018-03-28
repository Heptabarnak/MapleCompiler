#ifndef MAPLECOMPILER_LEFTVALUEVAR_H
#define MAPLECOMPILER_LEFTVALUEVAR_H


#include <variable/VarAccessor.h>
#include "LeftValue.h"
#include <string>

class LeftValueVar : public LeftValue {

private:
    VarAccessor *varAccessor;

public:
    LeftValueVar(VarAccessor *varAccessor);
    std::string getSymbolName() override;

    string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_LEFTVALUEVAR_H
