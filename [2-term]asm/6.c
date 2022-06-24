int foo(long long *a, long long *b){
    *a = 0;
    for(int i = 0; i != 10; i++){
        for(int j = 0; j != 10; j++){
            *a += *b+j;
        }
        b += 10;
    }
    return 0;
}
