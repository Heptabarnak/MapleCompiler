#include "Block.h"

Block::Block(const vector<Instruction *> &instructions) : instructions(instructions) {}

Block::~Block(){
    while(!instructions.empty()){
        instructions.pop_back();
    }
}
