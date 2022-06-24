void foo(double *x, double *a){
    double pr = *a;
    while(pr > 0){
        a++;
        pr += *x;
        *x = pr;
        pr = *a;
    }
}
