#include <stdio.h>
typedef unsigned long long ull;
ull nod(ull a, ull b) {
    while (b!=0) {
        a %= b;
        ull tmp=a;
        a=b;
        b=tmp;
    }
    return a;
}

int main() {
    ull n, ans=0;
    scanf("%lld",&n);
    ull cur=0, prev;
    for (ull i=0; i<n; i++) {
        prev=cur;
        scanf("%lld", &cur);
        if (i!=0) if (nod(cur, prev)!=1) ans+=1;
        if (i==n-1) {
            prev = cur;
        }
    }
    printf("%lld", ans);
    return 0;
}
