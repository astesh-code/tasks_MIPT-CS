#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
typedef struct edge_s{
    int a,b, len;
}edge;

int main() {
    const int INF_DIST=1000000000;
    int n,m,k,s,f;
    scanf("%d%d%d", &n, &m, &k);
    edge * edges = (edge *) malloc(m* sizeof(edge));
    int * fires = (int * ) malloc(k*sizeof (int));
    ull * dist = (ull *) calloc(n, sizeof(ull));
    for (int i=0; i<k; i++) {
        scanf("%d", &fires[i]);
        fires[i]--;
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].len);
        edges[i].a--;
        edges[i].b--;
    }
    scanf("%d%d", &s, &f);
    s--;
    f--;

    for (int i=0; i<n; i++) dist[i]=INF_DIST;
    dist[f]=0;
    int chd;
    do {
        chd=0;
        for (int i=0; i<m; i++){
            if (dist[edges[i].b]>dist[edges[i].a]+edges[i].len && dist[edges[i].a]<INF_DIST) {
                dist[edges[i].b]=dist[edges[i].a]+edges[i].len;
                chd=1;
            }
            if (dist[edges[i].a]>dist[edges[i].b]+edges[i].len && dist[edges[i].b]<INF_DIST) {
                dist[edges[i].a]=dist[edges[i].b]+edges[i].len;
                chd=1;
            }
        }
    } while (chd);

    for (int i=0; i<k; i++) if (dist[fires[i]] <= dist[s]) {
            printf("-1");
            return 0;
        }
    if (dist[s]<INF_DIST)printf("%lld", dist[s]);
    else printf("-1");
    return 0;
}
