#include <stdio.h>
#include <stdlib.h>

typedef struct edge_s{
    int a,b, len;
}edge;

int main() {
    const int INF_DIST=1000000;
    int n,m,s;
    scanf("%d%d%d", &n, &m, &s);
    edge * edges = (edge *) malloc(m* sizeof(edge));
    int * dist = (int *) calloc(n, sizeof(int));
    int * iter = (int *) calloc(n, sizeof(int));
    for (int i=0; i<m; i++) scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].len);
    for (int i=0; i<n; i++) dist[i]=INF_DIST;
    dist[s]=0;
    int chd, max_it=0;
    do {
        chd=0;
        for (int i=0; i<m; i++){
            if (dist[edges[i].b]>dist[edges[i].a]+edges[i].len && dist[edges[i].a]<INF_DIST) {
                dist[edges[i].b]=dist[edges[i].a]+edges[i].len;
                iter[edges[i].b]++;
                if (iter[edges[i].b]>max_it) max_it=iter[edges[i].b];
                chd=1;
            }
        }
    } while (chd && max_it<n);
    if (max_it>=n) printf("IMPOSSIBLE");
    else for (int i=0; i<n; i++) {
        if (dist[i]>=INF_DIST) printf("UNREACHABLE ");
        else printf("%d ", dist[i]);
    }
    return 0;
}
