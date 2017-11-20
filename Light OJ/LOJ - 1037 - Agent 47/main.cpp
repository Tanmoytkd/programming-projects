/*input

*/
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

int n, life[20];
int dp[1<<18];
char p[20][20];
int a[20][20];

int rec(int mask) {
    if(__builtin_popcount(mask)==n) return 0;
    if(dp[mask]==-1) {
        int res=INT_MAX;
        FOR(i, n) {
            if(mask&(1<<i)) continue;
            int damage=0;
            FOR(j, n) {
                if(mask&(1<<j)) damage=max(damage, a[j][i]);
            }
            if(damage==0) continue;
            int cost=(life[i]+damage-1)/damage;
            res=min(res, cost+rec(mask|((1<<i))));
        }
        dp[mask]=res;
    }
    return dp[mask];
}

int main()
{
    int t, tst = 1;
    sf1(t);

    while(t--) {
        sf1(n);
        mem(dp, -1);
        mem(a, 0);
        FOR(i, n) sf1(life[i]);
        FOR(i, n) {
            sf("%s", p[i]);
        }
        FOR(i, n) {
            FOR(j, n) {
                a[i][j]=max(1, p[i][j]-'0');
            }
        }

        int res=INT_MAX;
        FOR(i, n) {
            int mask=(1<<(i));
            res = min(res, life[i]+rec(mask));
        }
        pcase(tst++);
        pf1(res);
    }
    return 0;
}
