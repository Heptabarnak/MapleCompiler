#include "CFG.h"

using std::string;

BasicBlock *CFG::getRootBB() {
    return bbs.front();
}

CFG::CFG(SymbolTable *symbolTable) : symbolTable(symbolTable), nextBBNumber(0) {
    currentBB = new BasicBlock(this, newBBName());
    bbs.push_back(currentBB);
}

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

long CFG::getAllocationSize() {
    return symbolTable->getAllocationSize();
}

std::vector<BasicBlock *> &CFG::getBBs() {
    return bbs;
}

long CFG::getOffset(string name) {
    return symbolTable->getOffset(name);
}
