#include <stdio.h>

int min(int a, int b) {
    if (a<b) return a;
    else return b;
}
int max(int a, int b) {
    if (a>b) return a;
    else return b;
}

int bw (int a, int n) {
    int ans = 1;
    while (n!=0) {
        if (n & 1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

int getsym(int N, int K, int L) {
    if (K==1) {
        printf("%c", N+'a'-1);
        if (K<L) getsym(N, K+1, L);
    }
    else if (K<=L) {
            if (K<=bw(2, N-1))
                getsym(N - 1, K - 1, min(bw(2, N - 1) - 1, L-1));
            if (L>bw(2, N-1))
                getsym(N - 1, max(1, K-bw(2, N-1)), L - bw(2, N - 1));
    }
    return 0;
}

int main() {
    int n,k,l;
    scanf("%d%d%d", &n, &k, &l);
    getsym(n,k,l);
}
