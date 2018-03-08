#include <iostream>
#include <utility>
#include "ExprValue.h"


ExprValue::ExprValue(std::string i, std::string c)
        : integer(std::move(i)), character(std::move(c)) {

}

int64_t ExprValue::eval() {
    int64_t val = 0;

    if (!integer.empty()) {
        val = std::stoi(integer);
    } else {
        val = character.at(0);
    }

    std::cout << "TEST VALUE =" << val << std::endl;

    return val;
}
