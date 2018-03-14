#include "TabDeclaration.h"

TabDeclaration::TabDeclaration(Type type, const string &name, int size, const list<Value *> &definition) : type(type),
                                                                                                         name(name),
                                                                                                         size(size),
                                                                                                         definition(
                                                                                                                 definition) {}
