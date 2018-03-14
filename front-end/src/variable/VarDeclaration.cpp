#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(const string &name, Type type, Expr *assignment) : name(name), type(type),
                                                                                  assignment(assignment) {}
