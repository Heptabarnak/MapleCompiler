#include <ir/instructions/CallInstr.h>
#include "AccessorFunction.h"

using std::vector;
using std::string;

AccessorFunction::AccessorFunction(FunctionDefinition *declaration, vector<Expr *> *arguments)
        : declaration(declaration), arguments(arguments) {}

string AccessorFunction::getSymbolName() {
    return declaration->getSymbolName();
}

string AccessorFunction::buildIR(CFG *cfg) {
    vector<string> args;

    for (auto &&argument : *arguments) {
        args.push_back(argument->buildIR(cfg));
    }

    auto dest = cfg->createNewTmpVar(declaration->getType());
    auto instr = new CallInstr(cfg->currentBB, dest, declaration->getSymbolName(), args, declaration->getType());
    cfg->addIRInstr(instr);

    return dest;
}

Type AccessorFunction::getType() {
    return declaration->getType();
}
