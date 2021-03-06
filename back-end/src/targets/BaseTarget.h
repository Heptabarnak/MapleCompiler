#ifndef MAPLECOMPILER_BASETARGET_H
#define MAPLECOMPILER_BASETARGET_H


#include <iostream>
#include <fstream>
#include <string>
#include <ir/CFG.h>
#include <ir/instructions/OpInstr.h>
#include <ir/instructions/LoadConstInstr.h>
#include <ir/instructions/CallInstr.h>
#include <ir/instructions/RMemInstr.h>
#include <ir/instructions/WMemInstr.h>
#include <ir/instructions/UnaryOpInstr.h>
#include <Config.h>
#include <ir/instructions/IncrInstr.h>
#include <tree-walk/MapleTreeWalk.h>
#include <ir/instructions/RMemArrayInstr.h>
#include <ir/instructions/WMemArrayInstr.h>

class BaseTarget {
public:
    BaseTarget(Config *config, IRStruct* irStruct);

    virtual void parse() = 0;

    virtual void compile() = 0;

protected:
    // Stream functions
    void open();

    void close();

    void write(std::string line = "");

    bool isOpen();


    // Special parts
    virtual void prologue() = 0;

    virtual void epilogue() = 0;

    virtual void parseBasicBlocks() = 0;


    // Instructions available
    virtual void op(OpInstr *instr) = 0;

    virtual void loadConst(LoadConstInstr *instr) = 0;

    virtual void call(CallInstr *instr) = 0;

    virtual void rmem(RMemInstr *instr) = 0;

    virtual void wmem(WMemInstr *instr) = 0;

    virtual void rmemarray(RMemArrayInstr *instr) = 0;

    virtual void wmemarray(WMemArrayInstr *instr) = 0;

    virtual void unaryop(UnaryOpInstr *instr) = 0;

    virtual void incr(IncrInstr *instr) = 0;


    void instrDispacher(IRInstr *instr);


    // Variables used during parsing
    CFG *currentCFG;

    IRStruct* irStruct;

    Config *conf;

private:
    std::ofstream *output;
};


#endif //MAPLECOMPILER_BASETARGET_H
