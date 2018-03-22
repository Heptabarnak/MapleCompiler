#ifndef MAPLECOMPILER_CONTEXTLISTMAP_H
#define MAPLECOMPILER_CONTEXTLISTMAP_H

#include <vector>
#include <antlr4-runtime.h>

template<typename U, typename T>
std::vector<T> mapContext2Vector(
        const std::vector<U> &children,
        antlr4::tree::AbstractParseTreeVisitor *visitor
) {
    std::vector<T> vector;

    for (auto &&item : children) {
        vector.push_back((T) visitor->visit(item));
    }

    return vector;
}

#endif //MAPLECOMPILER_CONTEXTLISTMAP_H
