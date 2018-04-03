#ifndef MAPLECOMPILER_DECLARATION_H
#define MAPLECOMPILER_DECLARATION_H

#include <ir/BuildIR.h>class Declaration : public BuildIR{

public:
    virtual ~Declaration() = default;

    virtual int getAllocationSize() = 0;
};


#endif //MAPLECOMPILER_DECLARATION_H
