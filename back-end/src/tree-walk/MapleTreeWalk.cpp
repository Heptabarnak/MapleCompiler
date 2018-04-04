#include <function/FunctionDefinition.h>
#include <array/TabDeclaration.h>
#include <ir/globals/GlobalDeclarationVar.h>
#include <ir/globals/GlobalDeclarationTab.h>
#include "MapleTreeWalk.h"

using std::string;
using std::vector;
using std::map;

MapleTreeWalk::MapleTreeWalk(Start *start) : start(start) {}

IRStruct *MapleTreeWalk::generateIR() {
    auto irStruct = new IRStruct;

    irStruct->globalSymbolTable = start->getGlobalSymbolTable();

    auto declarations = start->getDeclarations();

    for (auto &&declaration : declarations) {
        if (auto funcDef = dynamic_cast<FunctionDefinition *>(declaration)) {
            if (funcDef->getSymbolTable() == nullptr) {
                // Example: putchar & getchar
                continue;
            }

            auto newCfg = new CFG(funcDef);
            funcDef->buildIR(newCfg);

            newCfg->addBB(newCfg->getReturnBlock());

            irStruct->cfgs.insert({funcDef->getSymbolName(), newCfg});
        } else if (auto varDef = dynamic_cast<VarDeclaration *>(declaration)) {
            long val = 0;

            if (varDef->getAssignment() != nullptr) {
                // Always simplifiable
                val = varDef->getAssignment()->simplify();
            }

            irStruct->globals.insert(
                    {varDef->getName(), new GlobalDeclarationVar(varDef->getName(), varDef->getType(), val)});
        } else if (auto tabDef = dynamic_cast<TabDeclaration *>(declaration)) {

            vector<long> *values = new vector<long>();

            if (auto defs = tabDef->getDefinition()) {
                for (auto &&def : *defs) {
                    values->push_back(def->getValue());
                }
            }

            irStruct->globals.insert(
                    {tabDef->getName(),
                     new GlobalDeclarationTab(tabDef->getName(), tabDef->getType(), tabDef->getSize(), values)});
        }
    }
    return irStruct;
}
