#include "FunctionParamVar.h"

FunctionParamVar::FunctionParamVar(const std::string &name, Type type)
        : VarDeclaration(name, type) {}

FunctionParamVar::FunctionParamVar(Type type) : VarDeclaration(type) {}

Type FunctionParamVar::getType() {
    return type;
}

std::string FunctionParamVar::getName() {
    return name;
}
