int foo(int *a, int n){
    if(n <= 0) return 0;
    int ans = *a;
    for(int i = 2; i < n; i += 2)
        ans += *a+i;
    return ans;
}
