#include <stdio.h>
#include <stdlib.h>

long long isprime(long long x) {
    long long i;
    for(i=2; i*i<=x; i++) {
        if(x%i==0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long i=3, counter=1, prime=2;
    printf("#%lld --> %lld\n", counter, prime);
    getch();
    while(counter<10001) {
        if(isprime(i)==1) {
            prime = i;
            counter++;
            printf("#%lld --> %lld\n", counter, prime);
            getch();
        }
        i+=2;
    }
    printf("\n%lld\n", prime);
    return 0;
}
