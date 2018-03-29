#include "UnaryOpInstr.h"

using std::string;

UnaryOpInstr::UnaryOpInstr(BasicBlock *bb_, UnaryOpInstr::UnaryOpType type, string var, string var1)
        : IRInstr(bb_), type(type), var(var), var1(var1) {

}
