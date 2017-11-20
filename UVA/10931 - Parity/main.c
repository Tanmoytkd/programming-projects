#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long n;
    scanf("%lld", &n);
    while(n!=0) {
        int sum=0, digits[1000], i=0, j;

        while(n>0) {
            digits[i]=n&1;
            sum+=digits[i];
            i++;
            n>>=1;
        }
        printf("The parity of ");

        for(j=i-1; j>=0; j--) printf("%d", digits[j]);

        printf(" is %d (mod 2).\n", sum);
        scanf("%lld", &n);
    }
    return 0;
}
