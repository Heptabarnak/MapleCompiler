#ifndef MAPLECOMPILER_TABDECLARATION_H
#define MAPLECOMPILER_TABDECLARATION_H

#include <token/Type.h>
#include <expression/Value.h>
#include <vector>
#include <string>
#include <declaration/Declaration.h>

class TabDeclaration : public Declaration {

private:
    Type type;
    std::string name;
    unsigned long size;
    std::vector<Value *> definition;

public:
    TabDeclaration(Type type, unsigned long size, const std::string &name, const std::vector<Value *> &definition = {});

    std::string buildIR(CFG *cfg) override;

    const std::string &getName() const;
};


#endif //MAPLECOMPILER_TABDECLARATION_H