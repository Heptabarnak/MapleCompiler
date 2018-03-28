#include "CFG.h"

BasicBlock *CFG::getRootBB() {
    return bbs.front();
}
