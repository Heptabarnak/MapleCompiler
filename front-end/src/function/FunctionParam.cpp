#include "FunctionParam.h"

using std::string;

FunctionParam::FunctionParam(const string &name, Type type) : VarDeclaration(name, type) {}

FunctionParam::FunctionParam(Type type) : VarDeclaration(type){

}
