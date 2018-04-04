#ifndef MAPLECOMPILER_CONFIG_H
#define MAPLECOMPILER_CONFIG_H

#include <string>

enum class Target {
    X86_64,
    JAVA,
    MSP430
};

typedef struct Config {
    bool staticAnalysis = false;
    bool optimisation = false;
    bool generateAsm = false;
    bool linkAsm = false;

    Target target = Target::X86_64;
    std::string fileToCompile{};
    std::string fileWithPath{};

} Config;

#endif //MAPLECOMPILER_CONFIG_H
