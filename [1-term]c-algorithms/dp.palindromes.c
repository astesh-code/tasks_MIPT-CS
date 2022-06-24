#include <stdio.h>
#include <stdlib.h>
int main() {
    char c;
    char * vec= (char *) malloc(sizeof (char));
    scanf("%c", &c);
    int n=0;
    while(c>='A' && c<='Z') {
        vec[n++]=c;
        char * tvec=(char *) realloc(vec,n+1);
        vec=tvec;
        scanf("%c", &c);
    }
    int ** a = (int**) malloc(n * sizeof(int*));
    for (int j = 0; j < n; j++) {
        a[j] = (int*) malloc(n * sizeof(int));
        a[j][j]=1;
    }
    for (int i=1; i < n; i++)
        for (int j=0; j<n; j++)
            if (j + i < n) {
                if (vec[j]==vec[j + i])
                    a[j][j+i] = a[j+1][j+i] + a[j][j+i-1] + 1;
                else
                    a[j][j+i] = a[j+1][j+i] + a[j][j+i-1] - a[j+1][j+i-1];
            }
    printf("%d", a[0][n-1]);
    return 0;
}
