int64_t addition(int64_t a, int64_t b, int64_t c, int64_t d, int64_t e, int64_t f, int64_t g)
{
    return (a+b+c+d+e+f+g);
}

void main()
{
    int64_t a = 5;
    int64_t b = 5;
    int64_t c = 5;
    int64_t d = 5;
    int64_t e = 5;
    int64_t f = 5;
    int64_t g = 5;

    int64_t digit;
    int64_t digits[20];
    int64_t i = 0;

    int64_t result = addition(a,b,c,d,e,f,g);

    while (result > 0) {
        digit = result % 10;
        digits[i] = digit;
        result /= 10;
        i++;
    }
    i--;
    while (i >= 0){
        putchar('0' + digits[i]);
        i--;
    }
}