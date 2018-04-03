#ifndef MAPLECOMPILER_LEFTVALUETAB_H
#define MAPLECOMPILER_LEFTVALUETAB_H


#include <array/TabAccessor.h>
#include "LeftValue.h"

class LeftValueTab : public LeftValue {

private:
    TabAccessor *tabAccessor;

public:
    explicit LeftValueTab(TabAccessor *tabAccessor);
    std::string getSymbolName() override;

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_LEFTVALUETAB_H
