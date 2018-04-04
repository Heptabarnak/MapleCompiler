#include<inttypes.h>

void displayString(char tab[], int64_t size) {
    while(--size) {
        putchar(tab[size]);
    }
}

void main() {
    int64_t t[10] = {
            1, 2, 3
    };

    char msg[] = "Bonjour, je m'appelle Marc-Antoine";

    displayString(msg, 34);

    putchar('\n');
}