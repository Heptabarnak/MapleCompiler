#ifndef MAPLECOMPILER_LEFTVALUEACCESSOR_H
#define MAPLECOMPILER_LEFTVALUEACCESSOR_H


#include "Accessor.h"

class LeftValueAccessor : public Accessor {
public:
    virtual Type getType() = 0;
};


#endif //MAPLECOMPILER_LEFTVALUEACCESSOR_H
