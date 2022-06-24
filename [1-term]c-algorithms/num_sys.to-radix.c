#include <stdio.h>

char int_to_sym(int a) {
    if (a>9) return 'A'+a-10;
    return a+'0';
}

void from_radix(const int base,  long long num){
    char part= int_to_sym(num%base);
    num/=base;
    if (num) from_radix(base, num);
    printf("%c", part);
}

int main() {
    int base;
    long long num;
    scanf("%lld %d",&num, &base );
    from_radix(base, num);
    return 0;
}
