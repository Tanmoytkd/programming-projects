#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long n, res;
    while(scanf("%lld", &n)==1 && n>-1) {
        res=n*(n+1)/2 + 1;
        printf("%lld\n", res);
    }
    return 0;
}
