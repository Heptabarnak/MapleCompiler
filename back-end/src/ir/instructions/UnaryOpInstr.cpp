#include "UnaryOpInstr.h"

UnaryOpInstr::UnaryOpInstr(BasicBlock *bb_, UnaryOpInstr::UnaryOpType type, std::string var, std::string var1)
        : IRInstr(bb_), type(type), var(var), var1(var1) {

}
