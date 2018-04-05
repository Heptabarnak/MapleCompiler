#include <token/Type.h>
#include <string>
#include <stdexcept>

#include "str2int.h"
#include "typeHelper.h"

Type getTypeFromString(const std::string &str) {
    switch (str2int(str.c_str())) {
        case str2int("char"):
            return Type::CHAR;
        case str2int("int32_t"):
            return Type::INT32_T;
        case str2int("int64_t"):
            return Type::INT64_T;
        case str2int("void"):
            return Type::VOID;
        default:
            throw std::runtime_error("Unable to parse TYPE");
    }
}

int getTypeAllocationSize(Type type) {
    switch (type) {
        case INT64_T:
            return 8;
        case INT32_T:
            return 4;
        case CHAR:
            return 1;
        case VOID:
            //Impossible
            return 0;
    }
}
