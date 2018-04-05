void main(int64_t result) {
    int64_t digit;
    int64_t digits[100];
    int64_t i = 0;

    while (result > 0) {
        digit = result % 10;
        digits[i] = digit;
        result /= 10;
        i++;
    }
    i--;
    while (i >= 0) {
        putchar('0' + digits[i]);
        i--;
    }
}