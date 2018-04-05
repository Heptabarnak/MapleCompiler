int64_t AckermannFunction(int64_t m, int64_t n){
    if(m == 0)
    {
        return (n+1);
    }
    else if (m>0 && n==0){
        return (AckermannFunction(m-1, 1));
    }
    else if (m>0 && n>0){
        return (AckermannFunction(m-1, AckermannFunction(m, n-1)));
    }
    else{
        return (-1);
    }
}

int64_t main(){
    int64_t m = 3;
    int64_t n = 4;

    int64_t result = AckermannFunction(m, n);

    int64_t digit;
    int64_t digits[20];
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
    putchar('\n');
}
