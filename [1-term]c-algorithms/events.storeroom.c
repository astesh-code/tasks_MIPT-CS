#include <stdio.h>
#include <stdlib.h>
typedef struct event_s {
    int time;
    int type;
} event;

int comparator(const void* p0, const void* p1)
{
    event * ps0 = (event*) p0;
    event * ps1 = (event*) p1;
    if (ps0->time==ps1->time) return ps0->type-ps1->time;
    return ps0->time-ps1->time;
}

int main() {
    int n;
    scanf("%d", &n);
    event * vec = malloc(2*n*sizeof(event));
    for (int i=0; i<n; i++) {
        int in_m, in_h, out_m, out_h;
        char rub;
        scanf("%d%c%d%c%d%c%d", &in_h, &rub, &in_m, &rub, &out_h, &rub, &out_m);
        vec[i].time=in_h*60+in_m;
        vec[i].type=1;
        vec[n+i].time=out_h*60+out_m;
        vec[n+i].type=-1;
    }
    qsort(vec, 2*n,sizeof (event),comparator);
    int max=0,ins=0;
    for (int i=0; i<2*n; i++) {
        ins+=vec[i].type;
        if (max<ins) max=ins;
    }
    printf("%d", max);
}
