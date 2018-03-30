#include <function/FunctionDefinition.h>
#include "CFG.h"

using std::string;

BasicBlock *CFG::getRootBB() {
    return bbs.front();
}

CFG::CFG(FunctionDefinition *funcDef) : funcDef(funcDef), nextBBNumber(0) {
    currentBB = new BasicBlock(this, newBBName());
    bbs.push_back(currentBB);
}

string CFG::createNewTmpVar(Type type) {
    return funcDef->getSymbolTable()->createNewTmpVar(type);
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
    return funcDef->getSymbolTable()->getAllocationSize();
}

std::vector<BasicBlock *> &CFG::getBBs() {
    return bbs;
}

long CFG::getOffset(string name) {
    return funcDef->getSymbolTable()->getOffset(name);
}

FunctionDefinition *CFG::getFunctionDefinition() {
    return funcDef;
}
