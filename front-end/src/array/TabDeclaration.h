#ifndef MAPLECOMPILER_TABDECLARATION_H
#define MAPLECOMPILER_TABDECLARATION_H

#include <token/Type.h>
#include <expression/Value.h>
#include <vector>
#include <string>
#include <declaration/Declaration.h>
#include <ir/BuildIR.h>

class TabDeclaration : public Declaration {

private:
    Type type;
    std::string name;
    unsigned long size;
    std::vector<Value *>* definition;

public:
    TabDeclaration(Type type, unsigned long size, const std::string &name, std::vector<Value *>* definition = nullptr);

    std::string buildIR(CFG *cfg) override;

    const std::string &getName() const;

    Type getType() const;

    unsigned long getSize() const;

    int getAllocationSize() override;

    std::vector<Value *> *getDefinition() const;
};


#endif //MAPLECOMPILER_TABDECLARATION_H
