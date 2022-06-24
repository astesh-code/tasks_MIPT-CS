#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int m, int * used, int ** vec) {
    used[m]=1;
    for (int i=0; i<n; i++) if (vec[m][i]==1)
        if (used[i]!=1)
            dfs(n, i, used, vec);
}

int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    int ** vec = (int **) calloc(n,sizeof (int*));
    for (int i=0; i<n; i++)
        vec[i]=(int *) calloc(n+1, sizeof (int)); //на списке смежности был RE по неизветсной мне причине
    for (int i=0; i<m;i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        vec[a][b]=1;
        vec[a][n]++;
        vec[b][a]=1;
        vec[b][n]++;
    }
    int * used = (int *) malloc(n*sizeof (int));
    dfs(n, 0, used, vec);
    for (int i=0; i<n; i++)
        if (used[i]!=1 || vec[i][n]%2==1) {
            printf("NO");
            return 0;
        }
    printf("YES");
    return 0;
}
