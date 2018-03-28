#ifndef MAPLECOMPILER_X86_64_H
#define MAPLECOMPILER_X86_64_H


#include "BaseTarget.h"

class X86_64 : public BaseTarget {
public:
    X86_64(const string &filename, map<string, CFG *> &cfgs);

    void parse() override;

    void compile() override;



};


#endif //MAPLECOMPILER_X86_64_H
