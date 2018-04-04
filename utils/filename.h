#ifndef MAPLECOMPILER_FILENAME_H
#define MAPLECOMPILER_FILENAME_H

#include <string>
#include <vector>
#include <sstream>
#include <iterator>

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string filename(const std::string &filename) {
    std::vector<std::string> tokens = split(filename, '/');

    std::string filenameWithoutPath = tokens[tokens.size() - 1];

    tokens = split(filenameWithoutPath, '.');

    std::string cleanFilename;
    for (int i = 0; i < tokens.size() - 1; i++) {
        cleanFilename += tokens[i];
    }

    return cleanFilename;
}


#endif //MAPLECOMPILER_FILENAME_H
