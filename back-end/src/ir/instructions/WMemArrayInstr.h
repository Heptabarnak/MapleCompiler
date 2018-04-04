#ifndef MAPLECOMPILER_WMEMARRAYINSTR_H
#define MAPLECOMPILER_WMEMARRAYINSTR_H


#include <ir/IRInstr.h>

class WMemArrayInstr  : public IRInstr {
public:
    WMemArrayInstr(BasicBlock *bb_, std::string value, std::string tab, std::string pos, Type type);

    std::string value;
    std::string tab;
    std::string pos;
    Type type;
};

#endif //MAPLECOMPILER_WMEMARRAYINSTR_H
