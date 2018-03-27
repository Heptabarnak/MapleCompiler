#include "MapleTreeWalk.h"

MapleTreeWalk::MapleTreeWalk(Start *start) : start(start) {}

void MapleTreeWalk::generateIR() {
    auto declarations = start->getDeclarations();

    for (auto &&declaration : declarations) {
        if (auto funcDef = dynamic_cast<FunctionDefinition *>(declaration)) {
            auto newCfg = new CFG(funcDef);
            funcDef->buildIR(newCfg);

            cfgs.insert({funcDef->getSymbolName(), newCfg});
        } else {
            // TODO Global var to IR
        }
    }
}
