
#ifndef ANTLR4CPP_FETCHER_STR2INT_H
#define ANTLR4CPP_FETCHER_STR2INT_H

constexpr unsigned int str2int(const char *str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

#endif //ANTLR4CPP_FETCHER_STR2INT_H
