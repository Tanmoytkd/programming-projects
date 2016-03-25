#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    printf("PERFECTION OUTPUT\n");

    int n;
    while(1) {
        scanf("%d", &n);
        if(n==0) break;

        int sum=0, i;

        if(n==1) sum=0;
        else if(n&1) {
            sum=1;
            for(i=3; i*i<n; i+=2) {
                if(n%i==0) sum+= i + (n/i);
            }
            if(i*i==n) sum+=i;
        }
        else {
            sum=1;
            for(i=2; i*i<n; i++) {
                if(n%i==0) sum+= i + (n/i);
            }
            if(i*i==n) sum+=i;
        }

        if(n<10) printf("    ");
        else if(n<100) printf("   ");
        else if(n<1000) printf("  ");
        else if(n<10000) printf(" ");

        printf("%d  ", n);

        if(sum==n) printf("PERFECT\n");
        else if(sum<n) printf("DEFICIENT\n");
        else printf("ABUNDANT\n");
    }

    printf("END OF OUTPUT\n");
    return 0;
}
