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
#define sf1(x) scanf("%I64d", &x)
#define sf2(x,y) scanf("%I64d %I64d", &x, &y)
#define sf3(x,y,z) scanf("%I64d %I64d %I64d", &x, &y, &z)
#define pf1(x) printf("%I64d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(long long I=0; I<N; I++)
#define FOR1(I, N) for(long long I=1; I<=N; I++)

using namespace std;

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}
typedef long long int lint;
int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    long long n, m, k;
    sf3(n,m,k);

    lint x,s;
    sf2(x,s);

    lint tm=x*n;

    lint a[m+5], b[m+5], c[k+5], d[k+5];

    FOR(i, m) sf1(a[i]);
    FOR(i, m) sf1(b[i]);

    FOR(i, k) sf1(c[i]);
    FOR(i, k) sf1(d[i]);

    a[m]=x;
    b[m]=0;

    FOR(i, m+1) {
        long long tt=x, mana=s;
        if(b[i]>s) continue;

        tt=a[i];

        long long total=tt*n;
        mana-=b[i];

        lint * pos= upper_bound(d, d+k, mana);
        if(pos!=d) {
            pos--;
            long long p=pos-d;
            total-=c[p]*tt;
        }

        if(total<tm) tm=total;
    }

    pf1(tm);
    return 0;
}
