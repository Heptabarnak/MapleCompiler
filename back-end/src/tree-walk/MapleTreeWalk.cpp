#include "MapleTreeWalk.h"

MapleTreeWalk::MapleTreeWalk(Start *start) : start(start) {}

std::map<std::string, CFG *> MapleTreeWalk::generateIR() {
    auto cfgs = std::map<std::string, CFG *>();
    auto declarations = start->getDeclarations();

    for (auto &&declaration : declarations) {
        if (auto funcDef = dynamic_cast<FunctionDefinition *>(declaration)) {
            auto newCfg = new CFG();
            funcDef->buildIR(newCfg);

            cfgs.insert({funcDef->getSymbolName(), newCfg});
        } else {
            // TODO Global var to IR
        }
    }
    return cfgs;
}
