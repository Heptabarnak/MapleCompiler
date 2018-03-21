#include "Block.h"

Block::Block(const list<Instruction *> &instructions) : instructions(instructions) {}

Block::~Block(){
    while(!instructions.empty()){
        instructions.pop_front();
    }
}
