#ifndef MAPLECOMPILER_STR2INT_H
#define MAPLECOMPILER_STR2INT_H

constexpr unsigned int str2int(const char *str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

#endif //MAPLECOMPILER_STR2INT_H
