#include <stdlib.h>
#include <stdio.h>
int main () {
    int n, k, min=0;
    unsigned long long sum=0;
    scanf("%d%d", &k, &n);
    int * vec = (int *) malloc(n* sizeof(int));
    for (int i=0; i<n; ++i) {
        scanf("%d", &vec[i]);
        if (min<vec[i]) min=vec[i];
        sum+=vec[i];
    }
    unsigned long long mid=0, l=min-1, r=sum;
    while (l+1<r) {
        mid=(l+r)/2;
        unsigned long long s=0;
        int m=1;
        for (int i=0; i<n; ++i) {
            if (s+vec[i]<=mid)
                s += vec[i];
            else{
                s=0;
                m++;
                i--;
            }

        }
        if (m>k) l=mid;
        else r=mid;
    }
    printf("%lld", r);
    return 0;
}
