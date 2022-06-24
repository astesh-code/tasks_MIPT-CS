#include <stdio.h>

typedef long long ull;

ull findsol (ull a, ull b, ull * x, ull * y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ull x1, y1;
    ull d = findsol (b%a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}
int main() {
    ull x,y, a,b;
    scanf("%lld%lld", &a,&b);
    findsol(a, b, &x, &y);
    if (x<0) printf("%lld", x+b);
    else printf("%lld", x);
}
