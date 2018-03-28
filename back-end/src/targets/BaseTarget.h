#ifndef MAPLECOMPILER_BASETARGET_H
#define MAPLECOMPILER_BASETARGET_H


#include <iostream>
#include <fstream>
#include <string>
#include <ir/CFG.h>

class BaseTarget {
public:
    BaseTarget(std::string filename, std::map<std::string, CFG *> &cfgs);

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
    virtual void binaryOp() = 0;

    virtual void loadConstant() = 0;


    // Variables used during parsing
    CFG *currentCFG;

    std::map<std::string, CFG *> cfgs;

private:
    std::ofstream *output;
    std::string filename;
};


#endif //MAPLECOMPILER_BASETARGET_H
