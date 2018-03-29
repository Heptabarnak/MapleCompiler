#include <function/FunctionDefinition.h>
#include "MapleTreeWalk.h"

using std::string;
using std::map;

MapleTreeWalk::MapleTreeWalk(Start *start) : start(start) {}

map<string, CFG *> MapleTreeWalk::generateIR() {
    auto cfgs = map<string, CFG *>();
    auto declarations = start->getDeclarations();

    for (auto &&declaration : declarations) {
        if (auto funcDef = dynamic_cast<FunctionDefinition *>(declaration)) {
            auto newCfg = new CFG(start->getGlobalSymbolTable());
            funcDef->buildIR(newCfg);

            cfgs.insert({funcDef->getSymbolName(), newCfg});
        } else {
            // TODO Global var to IR
        }
    }
    return cfgs;
}
