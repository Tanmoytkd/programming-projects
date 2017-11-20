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
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
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
int a[20][20];
int dp[20][1<<18];

int rec(int men, int mask) {
    if(men==n+1) return 0;
    if(dp[men][mask]==-1) {
        int res=0;
        FOR(i, n) {
            if((mask>>i)&1) continue;
            res=max(res, a[men][i]+rec(men+1, mask|(1<<i)));
        }
        dp[men][mask]=res;;
    }
    return dp[men][mask];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
        mem(dp, -1);
        sf1(n);
        FOR(i, n) {
            FOR(j, n) {
                sf1(a[i][j]);
            }
        }
        int res=rec(0, 0);
        pcase(tst++);
        pf1(res);
    }
    return 0;
}
