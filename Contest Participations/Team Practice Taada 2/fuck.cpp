#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi() printf("hi!\n")
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

lint n;

lint coin[502],weight[502];

lint dp[10007];


int main()
{
    //cout << sizeof dp << endl;
    int t;
    sf1(t);
    while(t--)
    {
        lint p,w;
        sf2ll(p, w);

        sf1ll(n);
        for(int i=0;i<n;i++)
        {
            lint a,b;
            sf2ll(a, b);
            coin[i] = a;
            weight[i] = b;
        }

        w-=p;

        FOR1(i, w) {
         dp[i]=INT_MAX;
        }
        dp[0]=0;

        FOR(i, n) {
            lint cw = weight[i];
            lint prize = coin[i];
            for(lint sack = cw; sack<=w; sack++) {
                dp[sack] = min(dp[sack], prize + dp[sack-cw]);
            }
        }

        lint res = dp[w];

        if(res==INT_MAX) cout << "This is impossible." << endl;
        else pf("The minimum amount of money in the piggy-bank is %lld.\n", res);

    }
}
