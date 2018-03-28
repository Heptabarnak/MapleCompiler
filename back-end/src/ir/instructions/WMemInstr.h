#ifndef MAPLECOMPILER_WMEMINSTR_H
#define MAPLECOMPILER_WMEMINSTR_H

#include <string>
#include <ir/IRInstr.h>

class WMemInstr : public IRInstr {
public:
    WMemInstr(BasicBlock *bb_, std::string var1, std::string var2);

    std::string var1;
    std::string var2;
};


#endif //MAPLECOMPILER_WMEMINSTR_H
