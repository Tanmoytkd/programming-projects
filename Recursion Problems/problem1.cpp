#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int change=1;

long long sum(long long n) {
    if(n==1) return 1;

    return n+ sum(n-change);
}

int main()
{
    long long n, res;
    while(scanf("%lld", &n)==1) {
        if(n<1) change = -1;
        else change = 1;
        res= sum(n);
        printf("%lld\n", res);
    }
    return 0;
}
