#ifndef MAPLECOMPILER_VARACCESSOR_H
#define MAPLECOMPILER_VARACCESSOR_H

#include <accessor/LeftValueAccessor.h>
#include "VarDeclaration.h"

class VarAccessor : public LeftValueAccessor {

private:
    VarDeclaration *declaration;

public:
    explicit VarAccessor(VarDeclaration *dec);

    std::string buildIR(CFG *cfg);

    std::string getSymbolName() override;

    Type getType() override;
};


#endif //MAPLECOMPILER_VARACCESSOR_H
