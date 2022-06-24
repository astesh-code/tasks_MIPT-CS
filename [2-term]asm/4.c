int foo(char *a, char* b){
    *b = *a;
    if(*b == 0) return 0;
    for (int i = 0; *b+i != 0; i++)
        b[i + 1] = a[i + 1];
    return i;
}
