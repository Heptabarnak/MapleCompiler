#include <function/FunctionDefinition.h>
#include "X86_64.h"
#include <ir/instructions/UnaryOpInstr.h>
#include <ir/globals/GlobalDeclarationVar.h>
#include <ir/globals/GlobalDeclarationTab.h>
#include <typeHelper.h>
#include <str2int.h>

using std::string;
using std::map;


static string gInstrExt(Type type) {
    switch (type) {
        case VOID:
            // Not possible;
            return 0;
        case CHAR:
            return "b";
        case INT32_T:
            return "l";
        case INT64_T:
            return "q";
    }
}

static string gReg(string reg, Type type) {

    switch (type) {
        case VOID:
            // Not possible;
            return 0;
        case CHAR:
            switch (str2int(reg.c_str())) {
                case str2int("rax"):
                    return "al";
                case str2int("rbx"):
                    return "bl";
                case str2int("rcx"):
                    return "cl";
                case str2int("rdx"):
                    return "dl";
                case str2int("rsi"):
                    return "sil";
                case str2int("rdi"):
                    return "dil";
                case str2int("rbp"):
                    return "bpl";
                case str2int("rsp"):
                    return "spl";
                case str2int("r8"):
                    return "r8b";
                case str2int("r9"):
                    return "r9b";
                case str2int("r10"):
                    return "r10b";
                case str2int("r11"):
                    return "r11b";
                case str2int("r12"):
                    return "r12b";
                case str2int("r13"):
                    return "r13b";
                case str2int("r14"):
                    return "r14b";
                case str2int("r15"):
                    return "r15b";
            }
        case INT32_T:
            switch (str2int(reg.c_str())) {
                case str2int("rax"):
                    return "eax";
                case str2int("rbx"):
                    return "ebx";
                case str2int("rcx"):
                    return "ecx";
                case str2int("rdx"):
                    return "edx";
                case str2int("rsi"):
                    return "esi";
                case str2int("rdi"):
                    return "edi";
                case str2int("rbp"):
                    return "ebp";
                case str2int("rsp"):
                    return "esp";
                case str2int("r8"):
                    return "r8d";
                case str2int("r9"):
                    return "r9d";
                case str2int("r10"):
                    return "r10d";
                case str2int("r11"):
                    return "r11d";
                case str2int("r12"):
                    return "r12d";
                case str2int("r13"):
                    return "r13d";
                case str2int("r14"):
                    return "r14d";
                case str2int("r15"):
                    return "r15d";
            }
            return 0;
        case INT64_T:
            return reg;
    }
}


X86_64::X86_64(Config *config, IRStruct *irStruct) : BaseTarget(config, irStruct) {}

void X86_64::parse() {
    open();

    // First the file header
    write("\t.file \"" + conf->fileToCompile + "\"");

    for (auto &&global : irStruct->globals) {
        write("\t.globl " + global.first);
        write("\t.data");
        write("\t.align 8"); // FIXME Alignment ?
        write("\t.type " + global.first + ", @object");

        if (auto var = dynamic_cast<GlobalDeclarationVar *>(global.second)) {
            write("\t.size " + var->name + ", " + std::to_string(getTypeAllocationSize(var->type)));

            write(var->name + ":");
            write("\t.quad " + std::to_string(var->value));

        } else if (auto tab = dynamic_cast<GlobalDeclarationTab *>(global.second)) {
            write("\t.size " + tab->name + ", " + std::to_string(tab->size * getTypeAllocationSize(tab->type)));

            write(tab->name + ":");

            for (auto &&value : *tab->values) {
                write("\t.quad " + std::to_string(value));
            }

            if (tab->size > tab->values->size()) {
                write("\t.zero " +
                      std::to_string(getTypeAllocationSize(tab->type) *
                                     (tab->size - tab->values->size()))
                );
            }
        }
    }

    for (auto cfg : irStruct->cfgs) {
        currentCFG = cfg.second;

        write("\t.text");
        write("\t.globl " + cfg.first);
        write("\t.type " + cfg.first + ", @function");

        // Add new label for the function
        write(cfg.first + ":");

        prologue();

        parseBasicBlocks();

        epilogue();
    }

    // It's the end so close the file
    close();
}

void X86_64::compile() {
    if (!system(nullptr)) {
        std::cerr << "[X86_64] Unable to create an executable, system() unavailable" << std::endl;
        throw std::runtime_error("System unavailable");
    }

    // Close .s file
    close();

    int result = system(("as -o " + conf->fileToCompile + ".o " + conf->fileToCompile + ".s").c_str());

    if (result != 0) {
        std::cerr << "[X86_64] Unable to assemble asm" << std::endl;
        throw std::runtime_error("Error while assemble source");
    }

    result = system(("gcc -static -o " + conf->fileToCompile + ".out " + conf->fileToCompile + ".o").c_str());

    if (result != 0) {
        std::cerr << "[X86_64] Unable to link executable" << std::endl;
        throw std::runtime_error("Error while linking executable");
    }
}

void X86_64::prologue() {

    write("\tpushq %rbp");
    write("\tmovq %rsp, %rbp");

    // Now we must add the correct size of variables

    long allocationSize = currentCFG->getAllocationSize();
    string subq = "\tsubq $" + std::to_string(allocationSize) + ", %rsp";

    write(subq);
    write("");

    // Load arguments
    auto args = currentCFG->getFunctionDefinition()->getParams();
    long size = args->size();

    if (size > 0) {
        FunctionParam *&pParam = args->at(0);
        write("\tmov" + gInstrExt(pParam->getType()) + " " + gReg("rdi", pParam->getType()) + ", " +
              getAsmForVar(pParam->getName()));
    }
    if (size > 1) {
        FunctionParam *&pParam = args->at(1);
        write("\tmov" + gInstrExt(pParam->getType()) + " " + gReg("rsi", pParam->getType()) + ", " +
              getAsmForVar(pParam->getName()));
    }
    if (size > 2) {
        FunctionParam *&pParam = args->at(2);
        write("\tmov" + gInstrExt(pParam->getType()) + " " + gReg("rdx", pParam->getType()) + ", " +
              getAsmForVar(pParam->getName()));
    }
    if (size > 3) {
        FunctionParam *&pParam = args->at(3);
        write("\tmov" + gInstrExt(pParam->getType()) + " " + gReg("rcx", pParam->getType()) + ", " +
              getAsmForVar(pParam->getName()));
    }
    if (size > 4) {
        FunctionParam *&pParam = args->at(4);
        write("\tmov" + gInstrExt(pParam->getType()) + " " + gReg("r8", pParam->getType()) + ", " +
              getAsmForVar(pParam->getName()));
    }
    if (size > 5) {
        FunctionParam *&pParam = args->at(5);
        write("\tmov" + gInstrExt(pParam->getType()) + " " + gReg("r9", pParam->getType()) + ", " +
              getAsmForVar(pParam->getName()));
    }

    if (size > 6) {
        auto size_offset = 16;
        for (auto it = args->begin() + 6; it != args->end(); ++it) {
            write("\tmovq " + std::to_string(size_offset) + "(%rbp), %rax");
            write("\tmov" + gInstrExt((*it)->getType()) + " " + gReg("rax", (*it)->getType()) + ", " +
                  getAsmForVar((*it)->getName()));
            size_offset += 8; // Force to 64bit stack
        }
    }
}

void X86_64::epilogue() {
    write("\tleave");
    write("\tret");
    write("");
}

void X86_64::parseBasicBlocks() {
    for (auto &&bb : currentCFG->getBBs()) {

        write("." + bb->label + ":");

        for (auto &&instr : bb->instrs) {
            instrDispacher(instr);
            write("");
        }

        // Jump to somewhere

        // Last basic block (return value always go to %rax)
        if (bb->exitTrue == nullptr) {
            return;
        }

        if (bb->exitFalse != nullptr) {
            // Conditional jump
            // TODO Check if last instr did a cmp
            // If yes, just do a jne otherwise, do first a cmp
            // For now, we add a cmp with %rax and 0
            write("\tmovq $0, %rbx");
            write("\tcmpq %rax, %rbx");
            write("\tjz ." + bb->exitFalse->label);
        }

        // Unconditional jump
        write("\tjmp ." + bb->exitTrue->label);
    }
}


void X86_64::op(OpInstr *instr) {

    auto left = instr->var1;
    auto right = instr->var2;
    auto dest = instr->var;
    auto type = instr->varType;

    auto raxReg = gReg("rax", type);
    auto rbxReg = gReg("rbx", type);

    // Move to registers
    write("\tmov" + gInstrExt(type) + " " + getAsmForVar(left) + ", " + raxReg);
    write("\tmov" + gInstrExt(type) + " " + getAsmForVar(right) + ", " + rbxReg);

    switch (instr->type) {
        case OpInstr::ADD:
            write("\tadd" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::SUB:
            write("\tsub" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::MULT:
            write("\timul" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::DIV:
            write("\tcd" + gInstrExt(type) + "");
            write("\tidiv" + gInstrExt(type) + " " + rbxReg);
            break;
        case OpInstr::MOD:
            write("\tcd" + gInstrExt(type) + "");
            write("\tidiv" + gInstrExt(type) + " " + rbxReg);
            write("\tmov" + gInstrExt(type) + " %rdx, " + raxReg);
            break;
        case OpInstr::EQUAL_EQUAL:
            write("\tcmp" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            // 0 per default, 1 if equal
            write("\tmov" + gInstrExt(type) + " $0, " + raxReg);
            write("\tmov" + gInstrExt(type) + " $1, " + rbxReg);
            write("\tcmove " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::NOT_EQUAL:
            write("\tcmp" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            // 0 per default, 1 if equal
            write("\tmov" + gInstrExt(type) + " $0, " + raxReg);
            write("\tmov" + gInstrExt(type) + " $1, " + rbxReg);
            write("\tcmovne " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::LESS_THAN:
            write("\tcmp" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            // 0 per default, 1 if >
            write("\tmov" + gInstrExt(type) + " $0, " + raxReg);
            write("\tmov" + gInstrExt(type) + " $1, " + rbxReg);
            write("\tcmovl " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::LESS_THAN_OR_EQ:
            write("\tcmp" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            // 0 per default, 1 if <=
            write("\tmov" + gInstrExt(type) + " $0, " + raxReg);
            write("\tmov" + gInstrExt(type) + " $1, " + rbxReg);
            write("\tcmovle " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::MORE_THAN:
            write("\tcmp" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            // 0 per default, 1 if >
            write("\tmov" + gInstrExt(type) + " $0, " + raxReg);
            write("\tmov" + gInstrExt(type) + " $1, " + rbxReg);
            write("\tcmovg " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::MORE_THAN_OR_EQ:
            write("\tcmp" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            // 0 per default, 1 if >=
            write("\tmov" + gInstrExt(type) + " $0, " + raxReg);
            write("\tmov" + gInstrExt(type) + " $1, " + rbxReg);
            write("\tcmovge " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::AND:
            write("\tand" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::OR:
            write("\tor" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::XOR:
            write("\txor" + gInstrExt(type) + " " + rbxReg + ", " + raxReg);
            break;
        case OpInstr::SHIFT_LEFT:
            write("\tmov" + gInstrExt(type) + " " + rbxReg + ", %rcx");
            write("\tsal" + gInstrExt(type) + " %cl, " + raxReg);
            break;
        case OpInstr::SHIFT_RIGHT:
            write("\tmov" + gInstrExt(type) + " " + rbxReg + ", %rcx");
            write("\tsar" + gInstrExt(type) + " %cl, " + raxReg);
            break;
    }

    write("\tmov" + gInstrExt(type) + " " + raxReg + ", " + getAsmForVar(dest));
}

void X86_64::loadConst(LoadConstInstr *instr) {
    write("\tmov" + gInstrExt(instr->type) + " $" + std::to_string(instr->value) + ", " + gReg("rax", instr->type));
    write("\tmov" + gInstrExt(instr->type) + " " + gReg("rax", instr->type) + ", " + getAsmForVar(instr->var));
}

void X86_64::call(CallInstr *instr) {
    auto args = instr->arguments;
    long size = args.size();

    if (size > 0) {
        write("\tmovq " + getAsmForVar(args.at(0)) + ", %rdi");
    }
    if (size > 1) {
        write("\tmovq " + getAsmForVar(args.at(1)) + ", %rsi");
    }
    if (size > 2) {
        write("\tmovq " + getAsmForVar(args.at(2)) + ", %rdx");
    }
    if (size > 3) {
        write("\tmovq " + getAsmForVar(args.at(3)) + ", %rcx");
    }
    if (size > 4) {
        write("\tmovq " + getAsmForVar(args.at(4)) + ", %r8");
    }
    if (size > 5) {
        write("\tmovq " + getAsmForVar(args.at(5)) + ", %r9");
    }
    if (size > 6) {
        for (auto it = args.rbegin(); it != (args.rend() - 6); ++it) {
            write("\tpushq " + getAsmForVar((*it)));
        }
    }

    write("\tcall " + instr->label);
    write("\tmov" + gInstrExt(instr->varType) + " %rax, " + getAsmForVar(instr->dest));
}

void X86_64::rmem(RMemInstr *instr) {
    write("\tmov" + gInstrExt(instr->varType) + " " + getAsmForVar(instr->var2) + ", " + gReg("rax", instr->varType));
    write("\tmov" + gInstrExt(instr->varType) + " " + gReg("rax", instr->varType) + ", " + getAsmForVar(instr->var1));
}

void X86_64::wmem(WMemInstr *instr) {
    write("\tmov" + gInstrExt(instr->varType) + " " + getAsmForVar(instr->var2) + ", " + gReg("rax", instr->varType));
    write("\tmov" + gInstrExt(instr->varType) + " " + gReg("rax", instr->varType) + ", " + getAsmForVar(instr->var1));
}

void X86_64::rmemarray(RMemArrayInstr *instr) {
    write("\tmovq " + getAsmForVar(instr->pos) + ", %rcx");
    write("\tmov" + gInstrExt(instr->type) + " " + getAsmForVar(instr->tab, true, instr->type) + ", " +
          gReg("rax", instr->type));
    write("\tmov" + gInstrExt(instr->type) + " " + gReg("rax", instr->type) + ", " + getAsmForVar(instr->dest));
}

void X86_64::wmemarray(WMemArrayInstr *instr) {
    write("\tmov" + gInstrExt(instr->type) + " " + getAsmForVar(instr->value) + ", " + gReg("rax", instr->type));
    write("\tmovq " + getAsmForVar(instr->pos) + ", %rcx");
    write("\tmov" + gInstrExt(instr->type) + " " + gReg("rax", instr->type) + ", " +
          getAsmForVar(instr->tab, true, instr->type));
}


void X86_64::unaryop(UnaryOpInstr *instr) {
    auto type = instr->varType;

    auto raxReg = gReg("rax", type);
    auto rbxReg = gReg("rbx", type);

    switch (instr->type) {
        case UnaryOpInstr::PLUS:
            write("\tmov" + gInstrExt(type) + " " + getAsmForVar(instr->var1) + ", " + raxReg);
            write("\tmov" + gInstrExt(type) + " " + raxReg + ", " + getAsmForVar(instr->var));
            break;
        case UnaryOpInstr::MINUS:
            write("\tmov" + gInstrExt(type) + " " + getAsmForVar(instr->var1) + ", " + raxReg);
            write("\tneg" + gInstrExt(type) + " " + raxReg);
            write("\tmov" + gInstrExt(type) + " " + raxReg + ", " + getAsmForVar(instr->var));
            break;
        case UnaryOpInstr::NOT :
            write("\tmov" + gInstrExt(type) + " $0, " + raxReg);
            write("\tmov" + gInstrExt(type) + " " + getAsmForVar(instr->var1) + ", " + rbxReg);
            write("\tcmp" + gInstrExt(type) + " " + raxReg + ", " + rbxReg);
            write("\tmov" + gInstrExt(type) + " $1, " + rbxReg);
            write("\tcmove " + rbxReg + ", " + raxReg);
            write("\tmov" + gInstrExt(type) + " " + raxReg + ", " + getAsmForVar(instr->var));
            break;
        case UnaryOpInstr::BITWISE_NOT :
            write("\tmov" + gInstrExt(type) + " " + getAsmForVar(instr->var1) + ", " + raxReg);
            write("\tnot" + gInstrExt(type) + " " + raxReg);
            write("\tmov" + gInstrExt(type) + " " + raxReg + ", " + getAsmForVar(instr->var));
            break;
    }
}

void X86_64::incr(IncrInstr *instr) {

    auto raxReg = gReg("rax", instr->varType);
    auto rbxReg = gReg("rbx", instr->varType);

    write("\tmov" + gInstrExt(instr->varType) + " " + getAsmForVar(instr->var1) + ", " + raxReg);
    write("\tmov" + gInstrExt(instr->varType) + " " + getAsmForVar(instr->var1) + ", " + rbxReg);
    switch (instr->type) {
        case IncrInstr::PLUS:
            write("\tinc" + gInstrExt(instr->varType) + " " + rbxReg);
            break;
        case IncrInstr::MINUS:
            write("\tdec" + gInstrExt(instr->varType) + " " + rbxReg);
            break;
    }

    write("\tmov" + gInstrExt(instr->varType) + " " + rbxReg + ", " + getAsmForVar(instr->var1));

    string reg = gReg(instr->isPostfix ? "rax" : "rbx", instr->varType);

    write("\tmov" + gInstrExt(instr->varType) + " " + reg + ", " + getAsmForVar(instr->var));

}


string X86_64::getAsmForVar(string var, bool isArray, Type type) {
    auto offset = currentCFG->getOffset(var);

    std::string ending = ")";

    if (isArray) {
        ending = ", %rcx, " + std::to_string(getTypeAllocationSize(type)) + ")";
    }

    if (offset != -1) {
        return "-" + std::to_string(offset) + "(%rbp" + ending;
    }
    return var + "(%rip" + ending;
}
