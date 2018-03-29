#include <ir/instructions/WMemInstr.h>
#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(const string &name, Type type, Expr *assignment) : name(name), type(type),
                                                                                  assignment(assignment) {}

const string &VarDeclaration::getName() const {
    return name;
}

string VarDeclaration::buildIR(CFG *cfg) {
    std::string value = cfg->createNewTmpVar(Type::INT64_T);
    std::string varAssignment = assignment->buildIR(cfg);

    cfg->addIRInstr(new WMemInstr(cfg->currentBB, value, varAssignment));

    return value;
}
