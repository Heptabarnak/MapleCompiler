#include "IRInstr.h"

IRInstr::IRInstr(BasicBlock *bb_, Type t, Target target) : bb(bb_), t(t), target(target) {}
