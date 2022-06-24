#include <stdio.h>
#include <stdlib.h>

int * binize(long long n, int * m) {
    int * ans = (int *) malloc(0);
    int i=0;
    while (n>0) {
        int *tans=(int *) realloc(ans, sizeof (int)*(i+1));
        ans=tans;
        int tmp=n%2;
        ans[i++]=tmp;
        n/=2;
    }
    *m=i;
    return ans;
}

typedef struct matrix_s {
    long long el[2][2];
}matrix;

matrix mul(matrix * a, matrix * b, long long mod) {
    matrix c;
    c.el[0][0]=((a->el[0][0]*b->el[0][0])%mod+(a->el[1][0]*b->el[0][1])%mod)%mod;
    c.el[1][0]=((a->el[0][0]*b->el[0][1])%mod+(a->el[0][1]*b->el[1][1])%mod)%mod;
    c.el[0][1]=((a->el[0][0]*b->el[0][1])%mod+(a->el[0][1]*b->el[1][1])%mod)%mod;
    c.el[1][1]=((a->el[1][1]*b->el[1][1])%mod+(a->el[1][0]*b->el[0][1])%mod)%mod;
    return c;
}

void matrix_pow(int n, matrix * vec, long long mod) {
    vec[n]=mul(&vec[n-1], &vec[n-1], mod);
}

void matrix_init(matrix * vec) {
    vec[1].el[0][0]=1;
    vec[1].el[1][0]=1;
    vec[1].el[0][1]=1;
    vec[1].el[1][1]=0;
    vec[0]=vec[1];
}

long long calc(long long n, long long mod) {
    int m=0;
    int * bin_list= binize(n, &m);
    matrix * vec = (matrix *) malloc((m+1)*sizeof (matrix));
    matrix_init(vec);
    for (int i=0; i<m; i++) {
        if (i<m-1) matrix_pow(i+1, vec, mod);
        if (bin_list[i]==1) vec[0] = mul(&vec[0], &vec[i], mod);
    }
    return vec[0].el[1][1];
}

int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld", calc(n, m));
    return 0;
}
