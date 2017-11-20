#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long n, fac;
    while(scanf("%lld", &n)==1) {
        int over=0, under=0, i;

        if(n<0) {
            if(n&1==1) over=1;
            else under=1;
        }

        fac=1;
        for(i=1; i<=n; i++) {
            fac*=i;
            if(fac>6227020800) {
                over = 1;
                break;
            }
        }
        if(over==1) printf("Overflow!\n");
        else if(fac<10000) printf("Underflow!\n");
        else printf("%lld\n", fac);
    }
    return 0;
}
