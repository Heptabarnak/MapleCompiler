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
    int64_t m = 2;
    int64_t n = 3;

    int64_t result = AckermannFunction(m, n);

    putchar('0' + result);
}
