#ifndef MAPLECOMPILER_X86_64_H
#define MAPLECOMPILER_X86_64_H


#include "BaseTarget.h"

class X86_64 : public BaseTarget {
public:
    X86_64(const string &filename, map<string, CFG *> &cfgs);

    void parse() override;

    void compile() override;


protected:
    void prologue() override;

    void epilogue() override;

    void parseBasicBlocks() override;

    void op(OpInstr *instr) override;

    void loadConst(LoadConstInstr *instr) override;

    void call(CallInstr *instr) override;

    void rmemarray(RMemArrayInstr *instr) override;

    void rmem(RMemInstr *instr) override;

    void wmem(WMemInstr *instr) override;

    void unaryop(UnaryOpInstr *instr) override;

};


#endif //MAPLECOMPILER_X86_64_H
