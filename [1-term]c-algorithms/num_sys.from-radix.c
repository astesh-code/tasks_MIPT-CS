#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int sym_to_int(char a) {
    if (a>'Z') return (int) a-87;
    else if (a>'9') return (int) a-55;
    else return a-'0';
}

long long pow_b (long long base, int n) {
    long long res = 1;
    while (n>0) {
        if (n & 1) {
            res *= base;
        }
        base *= base;
        n >>= 1;
    }
    return res;
}

long long to_radix(const int base, const int * a, const int size){
    long long ans=0;
    for (int i=0; i<size; i++) {
        long long step=a[i]*pow_b(base, size-i-1);
        ans+= step;
    }
    return ans;
}

int main() {
    int base;
    scanf("%d", &base);
    char tmp;
    int * num = (int *) malloc(sizeof(int));
    scanf("%c", &tmp);
    int i=0;
    scanf("%c", &tmp);

    while (tmp>='0'){

        num[i]= sym_to_int(tmp);
        i++;
        int *p = (int *) realloc(num, (i+1)*sizeof (int));
        assert(p!=NULL);
        num=p;
        scanf("%c", &tmp);
    }
    printf("%lld", to_radix(base, num, i));
    return 0;
}
