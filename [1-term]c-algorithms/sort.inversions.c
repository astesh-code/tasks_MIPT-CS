#include <stdio.h>
#include <stdlib.h>

unsigned long long inv_num=0;

int * merge(const int * a,const int * b, int len_a, int len_b) {
    int * c = (int *) malloc((len_a+len_b)* sizeof(int));
    int i=0,j=0,k=0;
    while (i<len_a || j<len_b) {
        if ((a[i]<=b[j] && i<len_a && j<len_b) || (i<len_a && j>=len_b)) {
            c[k]=a[i];
            i++;
        } else {
            inv_num+=(len_a-i);
            c[k]=b[j];
            j++;
        }
        k++;
    }
    return c;
}

int * divide(int * vec, int len){
    int * a, *b, *c;
    if (len>1) {
        if (len > 2) {
            a = divide(vec, (len / 2));
            b = divide(vec + (len / 2), len - (len / 2));
        } else {
            a = vec;
            b = vec + 1;
        }
        c = merge(a, b, (len / 2), len - (len) / 2);
    } else c = vec;
    return c;
}

int main() {
    int n;
    scanf("%d", &n);
    int * vec = (int *) malloc(n* sizeof(int));
    for (int i=0; i<n; i++) scanf("%d", &vec[i]);
    int * ans = divide(vec, n);
    printf("%lld", inv_num);
    return 0;
}
