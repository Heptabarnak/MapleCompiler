#ifndef MAPLECOMPILER_MAPLETREEWALK_H
#define MAPLECOMPILER_MAPLETREEWALK_H

#include <map>
#include <string>
#include <ir/CFG.h>
#include <axiom/Start.h>

class MapleTreeWalk {

public:
    MapleTreeWalk(Start *start);

    void generateIR();

private:

    Start *start;
    std::map<std::string, CFG *> cfgs;
};


#endif //MAPLECOMPILER_MAPLETREEWALK_H
