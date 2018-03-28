#include "CFG.h"

BasicBlock *CFG::getRootBB() {
    return bbs.front();
}

CFG::CFG(SymbolTable *symbolTable) : symbolTable(symbolTable), nextBBNumber(0) {}

std::string CFG::createNewTmpVar(Type type) {
    return symbolTable->createNewTmpVar(type);
}

std::string CFG::newBBName() {
    return "__BB__" + nextBBNumber++;
}

void CFG::addBB(BasicBlock *bb) {
    bbs.push_back(bb);
}

void CFG::addIRInstr(IRInstr *instr) {
    currentBB->addIRInstr(instr);
}
