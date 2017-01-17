#include<bits/stdc++.h>
#define pii pair<lint,lint>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%lld\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %lld: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(lint i=0;i<(x); i++)
#define FOR1(i, x) for(lint i = 1; i<=x ; i++)

using namespace std;
typedef long long lint;
typedef double dbl;

lint ncr[31][31], fact[31];

lint NCR(lint n, lint r) {
    if(n==r) return 1;
    if(r==1) return n;
    if(r==0) return 1;
    if(r>n) return 0;

    if(ncr[n][r]==-1) {
        ncr[n][r]= NCR(n-1, r)+ NCR(n-1, r-1);
    }
    return ncr[n][r];
}

int main()
{
    lint t, tst = 1;
    memset(ncr, -1, sizeof ncr);
    fact[0]=1;
    FOR1(i, 30) fact[i]=i*fact[i-1];

    sf1(t);
    while(t--) {
        lint n, r;
        lint res=0;
        sf2(n, r);
        if(r<=n) {
            res=NCR(n, r);

            res*=res*fact[r];

        }
        pf("Case %lld: %lld\n", tst++, res);
    }
    return 0;
}
