#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
    long long n, prime=1;
    scanf("%lld", &n);
    char isprime[n+1];
    long long i;
    for(i=0; i<=n; i++) {
        isprime[i]=1;
    }

    for(i=2; i<=n; i++) {
        if(isprime[i]==1) {
            long long j;
            for(j=i; j<=n; j+=i) {
                isprime[j]=0;
                if(j==n && i>prime) {
                    prime = i;
                }
            }
        }
    }

    if(isprime[n]==1) prime=n;
    printf("Largest Prime Factor = %lld", prime);
    return 0;
}
*/

int main()
{
    long long n, prime=1, i=2;
    scanf("%lld", &n);
    for(i=2; i*i<=n; i++) {
        if(n%i==0) {
            n/=i;
            if(i>prime) prime = i;
            i=2;
        }
    }
    if(n!=1) prime = n;
    printf("Largest prime factor = %d", prime);
    return 0;
}
