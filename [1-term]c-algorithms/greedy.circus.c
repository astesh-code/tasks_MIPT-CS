#include <stdio.h>
#include <stdlib.h>

int wp_comp(const void * val1, const void * val2) {
    if (*(int *)val1<*(int *)val2) return -1;
    else return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int * w= (int *) malloc(n* sizeof(int));
    int * p= (int *) malloc(n* sizeof(int));
    for (int i=0; i<n; i++) {
        scanf("%d%d", &w[i], &p[i]);
    }
    qsort(w, n, sizeof(int), wp_comp);
    qsort(p, n, sizeof(int), wp_comp);
    int w_sum=0, ans=0;
    for (int i=0; i<n; i++)
        if (i==0 || p[i]>=w_sum) {
            ans++;
            w_sum+=w[i];
        }
    printf("%d", ans);
    return 0;
}
