#include "BaseTarget.h"

using std::string;
using std::map;
using std::ofstream;

BaseTarget::BaseTarget(Config *config, IRStruct* irStruct)
        : conf(config), irStruct(irStruct) {
    output = new ofstream();
}

void BaseTarget::open() {
    output->open(conf->fileToCompile + ".s", std::ios_base::trunc);

    if (!output->is_open()) {
        // TODO Throw error
    }
}

void BaseTarget::close() {
    if (output->is_open()) {
        output->close();
    }
}

void BaseTarget::write(const string line) {
    // If not open, try to open it

    if (!output->is_open()) {
        // TODO Throw error
        return;
    }
    (*output) << line.c_str() << '\n';

}


void BaseTarget::instrDispacher(IRInstr *instr) {
    if (auto i = dynamic_cast<OpInstr *>(instr)) op(i);
    else if (auto i = dynamic_cast<LoadConstInstr *>(instr)) loadConst(i);
    else if (auto i = dynamic_cast<CallInstr *>(instr)) call(i);
    else if (auto i = dynamic_cast<RMemInstr *>(instr)) rmem(i);
    else if (auto i = dynamic_cast<WMemInstr *>(instr)) wmem(i);
    else if (auto i = dynamic_cast<RMemArrayInstr *>(instr)) rmemarray(i);
    else if (auto i = dynamic_cast<WMemArrayInstr *>(instr)) wmemarray(i);
    else if (auto i = dynamic_cast<UnaryOpInstr *>(instr)) unaryop(i);
    else if (auto i = dynamic_cast<IncrInstr *>(instr)) incr(i);
}

bool BaseTarget::isOpen() {
    return output->is_open();
}
