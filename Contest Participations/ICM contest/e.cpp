#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007LL


long long power(long long x, long long y, long long p=mod)
{
    long long res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y/2;
        x = (x*x) % p;
    }
    return res;
}

long long rec(int K, int N) {
    if(K==1) return power(2, N-1);
    if(N==0) return 0;

    long long mul = rec(K-1, N) - rec(K-1, N-1);
    mul = ((mul%mod)+mod)%mod;
    return (N*mul)%mod;
}

int main()
{
    long long N, K;
    cin >> N >> K;

    cout << rec(K, N) << endl;

    return 0;
}
