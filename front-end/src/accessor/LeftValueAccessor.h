#ifndef MAPLECOMPILER_LEFTVALUEACCESSOR_H
#define MAPLECOMPILER_LEFTVALUEACCESSOR_H


#include "Accessor.h"
#include "LeftValue.h"

class LeftValueAccessor : public Accessor {
private:
    LeftValue *leftValue;

public:
    explicit LeftValueAccessor(LeftValue *leftValue);

    std::string getSymbolName() override;

    std::string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_LEFTVALUEACCESSOR_H
