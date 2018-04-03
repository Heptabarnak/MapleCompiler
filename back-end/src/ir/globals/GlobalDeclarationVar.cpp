#include "GlobalDeclarationVar.h"

GlobalDeclarationVar::GlobalDeclarationVar(const std::string &name, Type type, long value)
        : GlobalDeclaration(name, type), value(value) {}