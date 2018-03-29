#include <ir/instructions/CallInstr.h>
#include "AccessorFunction.h"

using std::vector;
using std::string;

AccessorFunction::AccessorFunction(FunctionDefinition *declaration, vector<Expr *> const &arguments)
        : declaration(declaration), arguments(arguments) {}

string AccessorFunction::getSymbolName() {
    return declaration->getSymbolName();
}

string AccessorFunction::buildIR(CFG *cfg) {
    vector<string> args(arguments.size());

    for (auto &&argument : arguments) {
        args.push_back(argument->buildIR(cfg));
    }

    auto dest = cfg->createNewTmpVar(Type::INT64_T);
    auto instr = new CallInstr(cfg->currentBB, cfg->newBBName(), dest, declaration->getSymbolName(), args);
    cfg->addIRInstr(instr);

    return dest;
}
