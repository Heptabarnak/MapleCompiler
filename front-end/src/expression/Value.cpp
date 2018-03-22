#include "Value.h"

Value::Value(Type type, long value) : type(type), value(value) {}

long Value::getValue() {
    return value;
}
