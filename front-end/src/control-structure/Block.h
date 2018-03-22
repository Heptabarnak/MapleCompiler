#ifndef MAPLECOMPILER_BLOCK_H
#define MAPLECOMPILER_BLOCK_H


#include <vector>
#include "Instruction.h"

using std::vector;

class Block : public Instruction {

private:
    vector <Instruction *> instructions;

public:
    Block(const vector<Instruction *> &instructions);
    ~Block();
};


#endif //MAPLECOMPILER_BLOCK_H
