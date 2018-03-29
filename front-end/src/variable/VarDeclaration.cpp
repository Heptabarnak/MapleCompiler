#include "VarDeclaration.h"

using std::string;

VarDeclaration::VarDeclaration(const string &name, Type type, Expr *assignment) : name(name), type(type),
                                                                                  assignment(assignment) {}

const string &VarDeclaration::getName() const {
    return name;
}

string VarDeclaration::buildIR(CFG *cfg) {
    // TODO Loic VarDeclaration
    return std::__cxx11::string();
}
