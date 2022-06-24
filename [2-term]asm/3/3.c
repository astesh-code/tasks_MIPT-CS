int foo(int *a, int n){
    if(n > 2) {
    int i = 1;
    for (int i=1; i<n; i++) {
            int t = *a+i;
            *a+i = *a+i-1+;
            *a+i-1 = t;
        }
    }
    return n;
}
