#ifndef MAPLECOMPILER_TABDECLARATION_H
#define MAPLECOMPILER_TABDECLARATION_H

#include <token/Type.h>
#include <expression/Value.h>
#include <vector>
#include <string>


using std::vector;
using std::string;

class TabDeclaration {

private:
    Type type;
    string name;
    unsigned long size;
    vector<Value *> definition;

public:
    TabDeclaration(Type type, unsigned long size, const string &name, const vector<Value *> &definition = {});

};


#endif //MAPLECOMPILER_TABDECLARATION_H