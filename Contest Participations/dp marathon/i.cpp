#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

lint dp[55][55][55];

long long rec(int n, int k, int m) {
    if(n<k) return 0;
    if(n<0) return 0;
    if(k<0) return 0;
    if(n==0) {
        if(k==0) return 1;
        else return 0;
    }
    if(k==0) {
        if(n==0) return 1;
        else return 0;
    }

    if(dp[n][k][m]==-1) {
        long long & res= dp[n][k][m];
        res=0;

        FOR1(i, m) {
            res+=rec(n-i, k-1, m);
        }
    }
    //cout << n << " " << k << " " << m << " " << dp[n][k][m] << endl;
    return dp[n][k][m];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    mem(dp, -1);
    while(t--) {
        int n, m, k;
        sf3(n,k,m);

        long long res=rec(n, k, m);
        pf("Case %d: %lld\n", tst++, res);
    }
    return 0;
}
