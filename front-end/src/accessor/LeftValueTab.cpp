

#include "LeftValueTab.h"

LeftValueTab::LeftValueTab(TabAccessor *tabAccessor) : tabAccessor(tabAccessor) {}

std::string LeftValueTab::getSymbolName() {
    return tabAccessor->getName();
}

string LeftValueTab::buildIR(CFG *cfg) {
    return tabAccessor->buildIR(cfg);
}
