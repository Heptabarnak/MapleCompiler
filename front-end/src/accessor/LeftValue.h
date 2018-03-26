#ifndef MAPLECOMPILER_LEFTVALUE_H
#define MAPLECOMPILER_LEFTVALUE_H

#include "Accessor.h"
#include <string>

class LeftValue : public Accessor {
public:

    virtual std::string getSymbolName ()=0;

};


#endif //MAPLECOMPILER_LEFTVALUE_H
