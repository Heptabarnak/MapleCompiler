#include "AccessorFunction.h"

AccessorFunction::AccessorFunction(FunctionDefinition *declaration, const vector<Expr *> &arguments) : declaration(
        declaration), arguments(arguments) {}
