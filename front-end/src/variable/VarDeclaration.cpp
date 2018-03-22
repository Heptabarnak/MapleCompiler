#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(const string &name, Type type, Expr *assignment = nullptr) : name(name), type(type),
                                                                                  assignment(assignment) {}
