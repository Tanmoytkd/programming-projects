/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

typedef long long lint;

lint fact[2000001];

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    fact[0]=1;
    FOR1(i, 2e6) {
        fact[i]=(fact[i-1]*i) % mod;
    }

    int t;
    sf1(t);

    FOR1(test, t) {
        long long n, k;
        sf("%lld %lld", &n, &k);

        long long up=fact[n+k-1];
        long long low= (fact[n]*fact[k-1])%mod;

        low = bigmod(low, mod-2, mod);

        long long ans= (up*low)%mod;
        pf("Case %d: %lld\n", test, ans);
    }
    return 0;
}
