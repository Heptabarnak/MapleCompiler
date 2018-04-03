#include "FunctionParamTab.h"

FunctionParamTab::FunctionParamTab(const std::string &name, Type type, long size)
        : FunctionParam(name, type), size(size) {}
