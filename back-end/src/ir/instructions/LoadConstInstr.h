#ifndef MAPLECOMPILER_LDCONSTINSTR_H
#define MAPLECOMPILER_LDCONSTINSTR_H

#include <string>
#include <ir/IRInstr.h>
#include <token/Type.h>

class LoadConstInstr : public IRInstr {
public:
    LoadConstInstr(BasicBlock *bb_, std::string var, long value, Type type = Type::INT64_T);

    std::string var;
    long value;
    Type type;

};


#endif //MAPLECOMPILER_LDCONSTINSTR_H
