#include "Block.h"

using std::string;
using std::vector;

Block::Block(const vector<Instruction *> &instructions) : instructions(instructions) {}

Block::~Block() {
    while (!instructions.empty()) {
        delete instructions.back();
        instructions.pop_back();
    }
}

string Block::buildIR(CFG *cfg) {
    for (auto &&instruction : instructions) {
        instruction->buildIR(cfg);
    }
}
