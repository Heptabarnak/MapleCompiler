#include "FunctionParamTab.h"

FunctionParamTab::FunctionParamTab(const std::string &name, Type type, long size)
        : FunctionParam(name, type), size(size) {}

FunctionParamTab::FunctionParamTab(Type type) : FunctionParam(type) {}
