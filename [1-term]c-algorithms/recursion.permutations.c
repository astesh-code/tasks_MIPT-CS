#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
int find(int n, ll m, ll * const fact, int * numbers) {
    if (n>0) {
        int k;
        if (m) for (int i = 1; i <= n; i++) {
                if (m <= i * fact[n - 1] && m > (i - 1) * fact[n - 1]) k = i;
            } else k=1;
        printf("%d ", numbers[k]);
        for (int i=k; i<n; i++)
            numbers[i] = numbers[i + 1];
        if (k>1) {
            if (m%((k - 1) * fact[n - 1])) m %= (k - 1) * fact[n - 1];
            else m=(k - 1) * fact[n - 1];
        }
        find(n - 1, m, fact, numbers);
        }
    return 0;
}

int main() {
    int n;
    ll m;
    scanf("%d%lld", &n, &m);
    ll * fact = (ll *) malloc((n+1)*sizeof(ll));
    int * numbers = (int *) malloc((n+1)*sizeof(int));
    fact[0]=1;
    for (int i=1; i<n+1; i++) {
        fact[i]=fact[i-1]*i;
        numbers[i]=i;
    }
    find(n, m, fact, numbers);
    return 0;
}
