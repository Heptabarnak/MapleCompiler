#ifndef MAPLECOMPILER_MAPLETREEWALK_H
#define MAPLECOMPILER_MAPLETREEWALK_H

#include <map>
#include <string>
#include <ir/CFG.h>
#include <axiom/Start.h>

class MapleTreeWalk {

public:
    explicit MapleTreeWalk(Start *start);

    std::map<std::string, CFG *> generateIR();

private:
    Start *start;
};


#endif //MAPLECOMPILER_MAPLETREEWALK_H
