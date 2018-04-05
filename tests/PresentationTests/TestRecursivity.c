void recursiveFact(int64_t i){
    if(i > 0)   //FIXME : marche pas avec i > (-1) ?
    {
        putchar('0' + i);
        i = i - 1;
        recursiveFact(i);
    }
}

void main(){
    int64_t n = 4;
    recursiveFact(n);
    putchar('\n');
}
