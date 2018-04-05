#include<inttypes.h>


void main() {
    int32_t i = 0;
    int64_t z = 2;
    for(;i <6; i++){

    }
    putchar('0'+i);
    z++;
    z++;
    z++;
    putchar('0'+z);
    putchar('0'+ (z < 8));
    z++;
    z++;
    z++;
    putchar('0'+ (z < 8));
    putchar('0'+z);
}