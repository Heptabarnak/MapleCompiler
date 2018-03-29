#include "LeftValueAccessor.h"

using std::string;

LeftValueAccessor::LeftValueAccessor(LeftValue *leftValue) : leftValue(leftValue) {}

string LeftValueAccessor::getSymbolName() {
    return leftValue->getSymbolName();
}
