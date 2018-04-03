#include <ir/instructions/WMemInstr.h>
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

        cfg->addIRInstr(new WMemInstr(cfg->currentBB, name, defValue));
        return defValue;
    }
    return "";
}

int VarDeclaration::getAllocationSize() {
    return 8;
    // TODO Handle all size!
//    switch (type) {
//        case VOID:
//            // Should not append
//            throw std::runtime_error("VarDeclaration with VOID type");
//        case CHAR:
//            return 1;
//        case INT32_T:
//            return 4;
//        case INT64_T:
//            return 8;
//    }
}

VarDeclaration::VarDeclaration(Type type) : type(type){

}

Type VarDeclaration::getType() const {
    return type;
}

Expr *VarDeclaration::getAssignment() const {
    return assignment;
}
