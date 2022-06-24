#include <stdio.h>
#include <stdlib.h>

typedef struct num_with_pos_s{
    int num, pos;
} n_w_p;

int comp(const void *a, const void *b) {
    n_w_p an=*(n_w_p *)a, bn=*(n_w_p *)b;
    return an.num-bn.num;
}

int str_comp(const void **a, const void **b) {
    int *bn=*(int **)b+0;
    int *an=*(int **)a+0;
    return (an[0]>bn[0])-(an[0]<bn[0]);
}

void col_swap(int ** matrix, int ** copy, int n, int a, int b) {
    for (int i=0; i<n; i++) matrix[i][b]=copy[i][a];
}

void str_swap(int ** matrix, int a, int b){
    int * temp=matrix[a];
    matrix[a]=matrix[b];
    matrix[b]=temp;
}

void col_sort(int ** matrix, int ** copy, int n, int m) {
    n_w_p * f_line = (n_w_p *) malloc(m* sizeof(n_w_p));
    for (int j=0; j<m; j++) {
        f_line[j].num=matrix[0][j];
        f_line[j].pos=j;
    }
    qsort(f_line, m, sizeof(n_w_p), comp);
    for (int i=0; i<m; i++) col_swap(matrix, copy, n, f_line[i].pos, i);
}

int main() {
    int n, m, min=0, min_s;
    scanf("%d%d", &n, &m);
    int ** matrix = (int **) malloc(n* sizeof(int*));
    int ** copy = (int **) malloc(n* sizeof(int*));
    for (int i=0; i<n; i++) {
        matrix[i]=(int*) malloc(m* sizeof(int));
        copy[i]=(int*) malloc(m* sizeof(int));
        for (int j=0; j<m; j++) {
            scanf("%d", &matrix[i][j]);
            copy[i][j]=matrix[i][j];
            if (matrix[i][j]<min || min==0) {
                min=matrix[i][j];
                min_s=i;
            }
        }
    }
    str_swap(matrix, 0, min_s);
    str_swap(copy, 0, min_s);
    col_sort(matrix, copy, n, m);
    qsort(matrix, n, sizeof(int**), str_comp);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
