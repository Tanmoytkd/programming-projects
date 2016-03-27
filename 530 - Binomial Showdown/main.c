#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    while(1) {
        scanf("%d %d", &n, &k);
        if(n==0) break;

        unsigned long long res=1, i;

        if(k>(n>>1)) k=n-k;

        for(i=0; i<k; i++) {
            res *= n-i;
            res /= 1+i;
        }

        printf("%llu\n", res);
    }
    return 0;
}
