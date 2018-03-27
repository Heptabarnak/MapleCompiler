#ifndef MAPLECOMPILER_BUILDIR_H
#define MAPLECOMPILER_BUILDIR_H

#include "CFG.h"

class BuildIR {
    virtual void buildIR(CFG* cfg) = 0;
};


#endif //MAPLECOMPILER_BUILDIR_H
