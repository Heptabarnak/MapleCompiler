#ifndef MAPLECOMPILER_MAPLETREEWALK_H
#define MAPLECOMPILER_MAPLETREEWALK_H

#include <map>
#include <string>
#include <ir/CFG.h>
#include <ir/GlobalDeclaration.h>
#include <axiom/Start.h>

typedef struct IRStruct {
    std::map<std::string, CFG *> cfgs;
    std::map<std::string, GlobalDeclaration *> globals;
} IRStruct;

class MapleTreeWalk {

public:
    explicit MapleTreeWalk(Start *start);

    IRStruct* generateIR();

private:
    Start *start;
};


#endif //MAPLECOMPILER_MAPLETREEWALK_H
