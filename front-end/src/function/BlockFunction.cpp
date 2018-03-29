#include "BlockFunction.h"

using std::string;
using std::vector;

BlockFunction::BlockFunction(const vector<Declaration *> &declarations,
                             const vector<Instruction *> &instructions)
        : declarations(declarations), instructions(instructions) {}

string BlockFunction::buildIR(CFG *cfg) {
    // First, we need to add default values of declarations

    for (auto &&declaration : declarations) {
        declaration->buildIR(cfg);
    }

    // Now, we can just add every instruction for the block
    for (auto &&instruction : instructions) {
        instruction->buildIR(cfg);
    }

    return "";
}
