int64_t recursiveFact(int64_t fact){
    if(fact > 1)
    {
        return (fact*recursiveFact(fact-1));
    }
    else{
        return 1;
    }
}

int64_t main(){
    int64_t n = 4;

    int64_t result = recursiveFact(n);
    int64_t digit;
    int64_t digits[20];
    int64_t i = 0;

    while (result > 0) {
        digit = result % 10;
        digits[i] = digit;
        //putchar('0' + digit);
        result /= 10;
        i++;
    }
    i--;
    while (i >= 0){
        putchar('0' + digits[i]);
        i--;
    }
}
