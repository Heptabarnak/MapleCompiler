#include "TabDeclaration.h"

TabDeclaration::TabDeclaration(Type type, unsigned long size, const string &name, const vector<Value *> &definition)
        : type(type), size(size), name(name), definition(definition) {}