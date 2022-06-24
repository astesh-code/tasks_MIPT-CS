#include <stdio.h>
#include <stdlib.h>

int main() {
    char * word = (char *) malloc(0);
    char a=0;
    int l=0;
    do {
        l++;
        scanf("%c", &a);
        word = (char *) realloc(word, l);
        word[l-1]=a;
    } while (a>40);
    int word_size=l-1;
    l=0;
    char * pattern = (char *) malloc(0);
    do {
        l++;
        scanf("%c", &a);
        pattern = (char *) realloc(pattern, l);
        pattern[l-1]=a;
    } while (a>40);
    int pattern_size=l-1;
    int ** table = (int **) malloc((pattern_size+1)* sizeof(int*));
    for (int j=0; j<=pattern_size; j++) {
        table[j]=(int *) malloc((word_size+1)*sizeof(int));
        table[j][0]=0;
    }
    for (int i=0; i<word_size; i++) {
        table[0][i]=0;
    }
    int t=1;
    table[0][0]=1;
    for (int i=1; i<=pattern_size; i++) {
        for (int j=1; j<=word_size; j++) {
            if (pattern[i-1]==word[j-1] && table[i-1][j-1]==1) {
                table[i][j]=1;
                t=0;
            }
            else if (pattern[i-1]=='?' && table[i-1][j-1]==1) {
                table[i][j]=1;
                t=0;
            }
            else if (pattern[i-1]=='*' && (table[i-1][j]==1 || table[i][j-1]==1 || (i==1 && j==1))) table[i][j]=1;
            if (t) table[i][0]=1;
        }
    }
    if (table[pattern_size][word_size]==1) printf("YES");
    else printf("NO");
    return 0;
}
