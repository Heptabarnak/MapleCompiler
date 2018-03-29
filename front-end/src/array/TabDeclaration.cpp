#include "TabDeclaration.h"

using std::vector;
using std::string;

TabDeclaration::TabDeclaration(Type type, unsigned long size, const string &name, const vector<Value *> &definition)
        : type(type), size(size), name(name), definition(definition) {}

const string &TabDeclaration::getName() const {
    return name;
}
