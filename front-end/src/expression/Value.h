#ifndef MAPLECOMPILER_VALUE_H
#define MAPLECOMPILER_VALUE_H


#include <token/Type.h>

class Value {
private:
    Type type;
    int value;

public:
    Value(Type type, int value);

};


#endif //MAPLECOMPILER_VALUE_H
