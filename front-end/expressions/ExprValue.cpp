#include <iostream>
#include <utility>
#include "ExprValue.h"


ExprValue::ExprValue(std::string i, std::string c)
        : integer(std::move(i)), character(std::move(c)) {

}
