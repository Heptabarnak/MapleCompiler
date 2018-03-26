#include "TabAccessor.h"

TabAccessor::TabAccessor(TabDeclaration *declaration, Expr *pos) : declaration(declaration), pos(pos) {}

std::string TabAccessor::getName() {
    return declaration->getName();
}
