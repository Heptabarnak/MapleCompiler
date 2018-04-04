#include "LeftValueTab.h"

using std::string;

LeftValueTab::LeftValueTab(TabAccessor *tabAccessor) : tabAccessor(tabAccessor) {}

string LeftValueTab::getSymbolName() {
    return tabAccessor->getName();
}

string LeftValueTab::buildIR(CFG *cfg) {
    return tabAccessor->buildIR(cfg);
}

TabAccessor *LeftValueTab::getTabAccessor() const {
    return tabAccessor;
}
