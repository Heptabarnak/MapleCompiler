#ifndef MAPLECOMPILER_CONTEXTLISTMAP_H
#define MAPLECOMPILER_CONTEXTLISTMAP_H

#include <vector>
#include <antlr4-runtime.h>

template<typename U, typename T>
std::vector<T>* mapContext2Vector(
        const std::vector<U> &children,
        antlr4::tree::AbstractParseTreeVisitor *visitor
) {
    auto vector = new std::vector<T>(children.size());

    for (auto &&item : children) {
        vector->push_back((T) visitor->visit(item));
    }

    return vector;
}

template<typename U, typename T>
std::vector<T>* mapContext2VectorFlat(
        const std::vector<U> &children,
        antlr4::tree::AbstractParseTreeVisitor *visitor
) {
    auto vector = new std::vector<T>();

    for (auto &&item : children) {
        auto el = (std::vector<T>*) visitor->visit(item);
        vector->insert(vector->end(), el->begin(), el->end());
    }

    return vector;
}

#endif //MAPLECOMPILER_CONTEXTLISTMAP_H
