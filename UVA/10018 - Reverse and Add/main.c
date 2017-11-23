#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    long long testcase, i;
    scanf("%lld", &testcase);

    for(i=0; i<testcase; i++) {
        long long n, step=0, original;
        scanf("%lld", &n);
        original=n;

        while(1) {
            long long rev=0, x=n;
            while(x) {
                rev=rev*10+x%10;
                x/=10;
            }
            if(rev!=original && rev==n) break;
            n=n+rev;
            step++;
        }

        printf("%lld %lld\n", step, n);
    }
    return 0;
}
