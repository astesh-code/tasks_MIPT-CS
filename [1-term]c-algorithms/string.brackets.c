#include <stdlib.h>
#include <stdio.h>

int main () {
    int l=0, n=0, m=0;
    char c;
    char * opened = NULL;
    do {
        l++;
        scanf("%c", &c);
        if (c=='(' || c=='<' || c=='[' || c=='{') {
            n++;
            m++;
            opened = (char *) realloc(opened, m* sizeof(char));
            opened[n-1]=c;
        }
        else if (c==')' || c=='>' || c==']' || c=='}') {
            if (n>0 && ((c==')' && opened[n-1]=='(') || (c=='>' && opened[n-1]=='<')
            || (c=='}' && opened[n-1]=='{') || (c==']' && opened[n-1]=='['))) n--;
            else {
                printf("NO");
                return 0;
            }
        }
    } while (c>'&');
    if (n!=0) printf("NO");
    else printf("YES");
    return 0;
}
