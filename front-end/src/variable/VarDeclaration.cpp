#include <ir/instructions/WMemInstr.h>
#include <typeHelper.h>
#include "VarDeclaration.h"

using std::string;

VarDeclaration::VarDeclaration(const string &name, Type type, Expr *assignment) : name(name), type(type),
                                                                                  assignment(assignment) {}

const string &VarDeclaration::getName() const {
    return name;
}

string VarDeclaration::buildIR(CFG *cfg) {
    if (assignment) {

        auto defValue = assignment->buildIR(cfg);

        cfg->addIRInstr(new WMemInstr(cfg->currentBB, name, defValue, type));
        return defValue;
    }
    return "";
}

int VarDeclaration::getAllocationSize() {
    return getTypeAllocationSize(type);
}

VarDeclaration::VarDeclaration(Type type) : type(type){

}

Type VarDeclaration::getType() const {
    return type;
}

Expr *VarDeclaration::getAssignment() const {
    return assignment;
}
