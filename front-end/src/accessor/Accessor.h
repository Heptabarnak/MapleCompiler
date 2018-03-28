#ifndef MAPLECOMPILER_ACCESSOR_H
#define MAPLECOMPILER_ACCESSOR_H

#include <string>
#include <ir/BuildIR.h>

class Accessor : public BuildIR {
public:

    virtual std::string getSymbolName()=0;

};


#endif //MAPLECOMPILER_ACCESSOR_H
