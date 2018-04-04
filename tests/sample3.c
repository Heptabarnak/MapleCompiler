#include<inttypes.h>

void displayString(char tab[], int64_t size) {
    int64_t i = 0;

    for (; i < size; i++) {
        putchar(tab[i]);
    }
}

void main() {
    char tab[] = "Hello";
    int64_t size = 5;

    displayString(tab[2], size);

    putchar('\n');
}