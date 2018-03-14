#ifndef MAPLECOMPILER_BLOCK_H
#define MAPLECOMPILER_BLOCK_H


#include <list>
#include "Instruction.h"

using std::list;

class Block : public Instruction {

private:
    list <Instruction *> instructions;

public:
    Block(const list<Instruction *> &instructions);
};


#endif //MAPLECOMPILER_BLOCK_H
