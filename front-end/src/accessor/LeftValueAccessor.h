#ifndef MAPLECOMPILER_LEFTVALUEACCESSOR_H
#define MAPLECOMPILER_LEFTVALUEACCESSOR_H


#include "Accessor.h"
#include "LeftValue.h"

class LeftValueAccessor : public Accessor {
private:
    LeftValue *leftValue;

public:
    LeftValueAccessor(LeftValue *leftValue);
};


#endif //MAPLECOMPILER_LEFTVALUEACCESSOR_H
