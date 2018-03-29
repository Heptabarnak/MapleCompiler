#include "CFG.h"

using std::string;

BasicBlock *CFG::getRootBB() {
    return bbs.front();
}

CFG::CFG(SymbolTable *symbolTable) : symbolTable(symbolTable), nextBBNumber(0) {}

string CFG::createNewTmpVar(Type type) {
    return symbolTable->createNewTmpVar(type);
}

string CFG::newBBName() {
    return "__BB__" + nextBBNumber++;
}

void CFG::addBB(BasicBlock *bb) {
    bbs.push_back(bb);
}

void CFG::addIRInstr(IRInstr *instr) {
    currentBB->addIRInstr(instr);
}
