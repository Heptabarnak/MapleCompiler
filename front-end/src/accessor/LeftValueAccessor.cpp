#include "LeftValueAccessor.h"

LeftValueAccessor::LeftValueAccessor(LeftValue *leftValue) : leftValue(leftValue) {}

std::string LeftValueAccessor::getSymbolName() {
    return leftValue->getSymbolName();
}
