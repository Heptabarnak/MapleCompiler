#include "FunctionParamTab.h"

FunctionParamTab::FunctionParamTab(const std::string &name, Type type, int size) : FunctionParam(name, type) {
    this->size = size;
}
