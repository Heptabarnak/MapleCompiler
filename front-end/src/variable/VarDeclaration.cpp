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
    switch (type) {
        case VOID:
            // Should not append
            throw std::runtime_error("VarDeclaration with VOID type");
        case CHAR:
            return 1;
        case INT32_T:
            return 4;
        case INT64_T:
            return 8;
    }
}
