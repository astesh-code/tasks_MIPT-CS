#include <stdio.h>
#include <math.h>
int main(){
    int x,y,a,b,a1,b1;
    scanf("%d%d%d%d%d%d", &x,&y,&a,&b,&a1,&b1);
    int A=(b1-b);
    int B=(a1-a);
    int C=(A*a-B*b);
    double length=sqrt(A*A+B*B);
    double rect=fabs(A*x-B*y-C)/length;
    double to_second=sqrt((x-a1)*(x-a1)+(y-b1)*(y-b1));
    double to_first=sqrt((a-x)*(a-x)+(b-y)*(b-y));
    double second_proj=sqrt(fabs(to_second*to_second-rect*rect));
    double first_proj=sqrt(fabs(to_first*to_first-rect*rect));
    if (second_proj<length && first_proj<length) printf("%.6lf", rect);
    else if (to_first<to_second) printf("%.6lf", to_first);
    else printf("%.6lf", to_second);
    return 0;
}
