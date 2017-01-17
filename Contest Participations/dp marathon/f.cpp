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

int n;
int costs[22][3];
int dp[22][3];

int go(int pos, int col) {
    if(pos==n-1) return costs[pos][col];

    if(dp[pos][col]==-1) {
        int ret=INT_MAX;

        FOR(i, 3) {
            if(i==col) continue;
            ret=min(ret, costs[pos][col]+go(pos+1, i));
        }

        dp[pos][col]=ret;
    }
    return dp[pos][col];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
        mem(dp, -1);
        sf1(n);

        FOR(i, n) {
            FOR(j, 3) {
                sf1(costs[i][j]);
            }
        }

        int res=INT_MAX;
        FOR(i, 3) {
            res=min(res, go(0,i));
        }

        pcase(tst++);
        printf("%d\n", res);
    }
    return 0;
}
