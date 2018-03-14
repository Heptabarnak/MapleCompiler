#include "AccessorFunction.h"

AccessorFunction::AccessorFunction(FunctionDefinition *declaration, const list<Expr *> &arguments) : declaration(
        declaration), arguments(arguments) {}
