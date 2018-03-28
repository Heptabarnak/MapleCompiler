#ifndef MAPLECOMPILER_VARACCESSOR_H
#define MAPLECOMPILER_VARACCESSOR_H

#include <ir/BuildIR.h>
#include "VarDeclaration.h"

class VarAccessor : public BuildIR {

private:
    VarDeclaration *declaration;

public:
    VarAccessor(VarDeclaration *dec);

    std::string getName();

    string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_VARACCESSOR_H
