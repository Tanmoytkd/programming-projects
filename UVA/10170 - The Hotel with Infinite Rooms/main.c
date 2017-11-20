#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long s, d;
    while(scanf("%lld %lld", &s, &d)==2) {
        while(d>s) {
            d-=s;
            s++;
        }
        printf("%lld\n", s);
    }
    return 0;
}
