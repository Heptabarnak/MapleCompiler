#ifndef MAPLECOMPILER_VALUE_H
#define MAPLECOMPILER_VALUE_H


#include <token/Type.h>

class Value {
private:
    Type type;
    long value;

public:
    Value(Type type, long value);


    Type getType() const;

    long getValue();
};


#endif //MAPLECOMPILER_VALUE_H
