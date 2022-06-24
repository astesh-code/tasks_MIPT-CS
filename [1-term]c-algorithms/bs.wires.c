#include <stdio.h>
#include <stdlib.h>
int main () {
    int n, k, sum=0, max=0;
    scanf("%d%d", &n,&k);
    int *vec=(int*) malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        int temp;
        scanf("%d", &temp);
        vec[i]=temp;
        if (vec[i]>max) max=vec[i];
        sum+=vec[i];
    }
    int l=0, r=max+1, mid;
    while (l+1<r) {
        mid=(l+r)/2;
        int tempsum=0;
        for (int i=0; i<n; ++i) {
            tempsum+=vec[i]/mid;
        }
        if (tempsum>=k) l=mid;
        else r=mid;
    }
    printf("%d", r-1);
    return 0;
}
