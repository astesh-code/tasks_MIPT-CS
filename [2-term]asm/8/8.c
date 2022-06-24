int foo(char* s){
    int ans = 0;
    while(*s){
        char c = *s - '0';
        if(c > 9 or c < 0)
            return 0;
        ans *= 10;
	ans += c;
        *s+=1;
    }
    return ans;
}
