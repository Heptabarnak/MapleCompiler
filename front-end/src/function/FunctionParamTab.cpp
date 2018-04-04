#include "FunctionParamTab.h"

FunctionParamTab::FunctionParamTab(Type type, long size, const std::string &name)
        : TabDeclaration(type, size, name) {}

FunctionParamTab::FunctionParamTab(Type type) : FunctionParam(type) {}

Type FunctionParamTab::getType() {
    return type;
}

std::string FunctionParamTab::getName() {
    return name;
}
