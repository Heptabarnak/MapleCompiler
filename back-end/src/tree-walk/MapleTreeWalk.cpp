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
            if (funcDef->getSymbolTable() == nullptr) {
                // Example: putchar & getchar
                continue;
            }

            auto newCfg = new CFG(funcDef);
            funcDef->buildIR(newCfg);

            cfgs.insert({funcDef->getSymbolName(), newCfg});
        } else {
            // TODO Global var to IR
        }
    }
    return cfgs;
}
