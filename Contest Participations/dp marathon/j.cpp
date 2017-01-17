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

#define mod 100000007

int dp[101][10001];
int coin[100], total[100];
int n, k;

int go(int pos, int money) {
    if(money<0) return 0;
    if(pos>=n) {
        if(money==0) return 1;
        else return 0;
    }

    if(dp[pos][money]==-1) {
        int res=0;
        FOR(i, k+1) {
            int totalcoin= i*coin[pos];
            if(totalcoin>money) break;
            res+=(go(pos+1, money-totalcoin)%mod);
            res%=mod;
        }
        dp[pos][money]=res;
    }
    return dp[pos][money];
}

int main()
{
    int t, tst = 1;
    sf1(t);


    while(t--) {
        memset(dp, -1, sizeof dp);

        sf2(n, k);
        FOR(i, n) sf1(coin[i]);
        int res=go(0, k);
        res%=mod;

        pf("Case %d: %d\n", tst++, res);
    }
    return 0;
}
