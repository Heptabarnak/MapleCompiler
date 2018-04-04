#ifndef MAPLECOMPILER_PARSECONFIG_H
#define MAPLECOMPILER_PARSECONFIG_H

#include <Config.h>
#include <iostream>
#include <unistd.h>
#include "str2int.h"
#include "filename.h"

Config *parseConfig(int argc, char *const *argv) {
    const static auto usage = "Usage: ./mapleCompiler [-a] [-o] [-c] [-t <x64|msp430|java>] <file.c>";
    if (argc < 2) {
        std::cerr << "Not enough arguments" << std::endl;
        std::cerr << usage << std::endl;
        return nullptr;
    }

    auto config = new Config();

    // Shut GetOpt error messages down (return '?'):
    opterr = 0;
    int opt;

    while ((opt = getopt(argc, argv, "-aoclt:")) != -1) {
        switch (opt) {
            case 'a':
                config->staticAnalysis = true;
                break;
            case 'o':
                config->optimisation = true;
                break;
            case 'c':
                config->generateAsm = true;
                break;
            case 'l':
                config->linkAsm = true;
                break;
            case 't':
                switch (str2int(optarg)) {
                    case str2int("x64"):
                        config->target = Target::X86_64;
                        break;
                    case str2int("msp430"):
                        config->target = Target::MSP430;
                        break;
                    case str2int("java"):
                        config->target = Target::JAVA;
                        break;
                    default:
                        std::cerr << "Unknown target option: '" << optarg << "'!" << std::endl;
                        std::cerr << usage << std::endl;
                        return nullptr;
                }
                break;
            case '\1':
                config->fileToCompile = filename(std::string(optarg));
                config->fileWithPath = std::string(optarg);
                break;
            case '?':
                std::cerr << "Unknown option: '" << char(optopt) << "'!" << std::endl;
                std::cerr << usage << std::endl;
                return nullptr;
            default:
                break;
        }
    }

    return config;
}

#endif //MAPLECOMPILER_PARSECONFIG_H
