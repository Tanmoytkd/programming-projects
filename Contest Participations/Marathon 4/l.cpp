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
typedef long long lint;
lint fact[10005];

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

long long ncr(long long n, long long r) {
    if(r>n) return 0;
    if(r==n) return 1;
    if(r==0) return 1;
    if(r==1) return n;

    long long up=fact[n];
    long long down= (fact[r]*fact[n-r])%mod;
    down=bigmod(down, mod-2, mod);
    long long res=(up*down)%mod;
    return res;
}



int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif
    fact[0]=1;

    FOR1(i, 10005) {
        fact[i]=(fact[i-1]*i)%mod;
    }

    lint n, k;

    while(sf("%lld %lld", &n, &k)==2) {
        if(n==0 && k==0) break;
        long long D, R;
        if((k+1)&1) {
            D=(k+1)/2;
            R=D+1;
        }
        else {
            D=(k+1)/2;
            R=D;
        }

            long long res= (ncr(n-1-1, D-1)*ncr(n-1-1, R-1))%mod;
            res*=2;
            res%=mod;

            pf("%lld\n", res);
    }

    return 0;
}
