#ifndef MAPLECOMPILER_BLOCK_H
#define MAPLECOMPILER_BLOCK_H


#include <vector>
#include "Instruction.h"


class Block : public Instruction {

private:
    std::vector <Instruction *> instructions;

public:
    explicit Block(const std::vector<Instruction *> &instructions);
    ~Block();

    std::string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_BLOCK_H
