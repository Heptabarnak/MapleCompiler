#include "GlobalDeclarationTab.h"

GlobalDeclarationTab::GlobalDeclarationTab(const std::string &name, std::vector<long> *values)
        : GlobalDeclaration(name), values(values) {}
