#include <stdio.h>

int main() {
    int p,q;
    scanf("%d%d", &p, &q);
    int div, fac_num=1;
    while (p) {
        fac_num++;
        p*=fac_num;
        div=p/q;
        p%=q;
        printf("%d ", div);
    }
    return 0;
}
