#include "AccessorFunction.h"

AccessorFunction::AccessorFunction(FunctionDefinition *declaration, vector<Expr *> const &arguments)
        : declaration(declaration), arguments(arguments) {}
