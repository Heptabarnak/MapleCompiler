#include "GlobalDeclarationTab.h"

GlobalDeclarationTab::GlobalDeclarationTab(const std::string &name, Type type, unsigned long size,
                                           std::vector<long> *values)
        : GlobalDeclaration(name, type), size(size), values(values) {}
