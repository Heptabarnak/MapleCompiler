#ifndef MAPLECOMPILER_BUILDIR_H
#define MAPLECOMPILER_BUILDIR_H

#include <string>
#include "CFG.h"

class BuildIR {

public:
    virtual std::string buildIR(CFG *cfg) = 0;
};


#endif //MAPLECOMPILER_BUILDIR_H
