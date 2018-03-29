#ifndef MAPLECOMPILER_CONFIG_H
#define MAPLECOMPILER_CONFIG_H

#include <string>

enum Target {
    X86_64,
    JAVA,
    MSP430
};

typedef struct Config {
    bool staticAnalysis = false;
    bool optimisation = false;
    bool generateAsm = false;
    bool linkAsm = false;

    Target target = X86_64;
    std::string fileToCompile{};

} Config;

#endif //MAPLECOMPILER_CONFIG_H
