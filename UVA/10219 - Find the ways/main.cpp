#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    long long n, k;
    while(scanf("%lld %lld", &n, &k)==2) {
        long double res=0;
        for(unsigned long long i=n-k+1; i<=n; i++) res+= log10((double)i);
        for(unsigned long long i=1; i<=k; i++) res-=log10((double)i);
        int result= floor(res)+1;
        printf("%d\n", result);
    }

    return 0;
}
