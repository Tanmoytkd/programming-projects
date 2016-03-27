#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(1) {
        scanf("%d", &n);
        if(n==0) break;

        int digits=1, pals=9;

        while(n>pals) {
            n-=pals;
            digits++;
            if(n<=pals) break;

            n-=pals;
            digits++;

            pals*=10;
        }

        int res=1, i, dig=(digits+1)>>1;
        for(i=1; i<dig; i++) {
            res*=10;
        }

        res+=n-1;

        printf("%d", res);
        if(digits&1) res/=10;
        while(res) {
            printf("%d", res%10);
            res/=10;
        }

        printf("\n");


    }
    return 0;
}
