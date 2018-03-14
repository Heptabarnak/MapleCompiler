#ifndef MAPLECOMPILER_LEFTVALUETAB_H
#define MAPLECOMPILER_LEFTVALUETAB_H


#include <array/TabAccessor.h>
#include "LeftValue.h"

class LeftValueTab : public LeftValue {

private:
    TabAccessor *tabAccessor;

public:
    LeftValueTab(TabAccessor *tabAccessor);
};


#endif //MAPLECOMPILER_LEFTVALUETAB_H
