#include <stdio.h>
#include <stdlib.h>

long long gcd(long long i, long long j) {
    long long l=i, s=j, rem;
    if(l<s) {
        l=j;
        s=i;
    }
    rem=l%s;
    while(rem!=0) {
        l=s;
        s=rem;
        rem=l%s;
    }
    return s;
}

int main()
{
    long long i=2, j=3;
    while(j<=20) {
        printf("%lld*%lld/%lld=", i, j, gcd(i,j));
        i = i*j/gcd(i,j);
        printf("%lld\n", i);
        j++;
    }
    printf("\nSmallest multiple = %lld\n", i);
    return 0;
}
