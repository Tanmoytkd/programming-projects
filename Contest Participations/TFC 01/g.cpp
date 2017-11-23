#include<bits/stdc++.h>
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

lint n, w;
lint arr[40];
map<long long, int> dp[40];

long long go(int pos, lint sum) {
	if(pos>=n) {
		if(sum<=w) return 1;
		else return 0;
	}

	if(sum>w) return 0;

	if(dp[pos].count(sum)) return dp[pos][sum];

	return dp[pos][sum]=go(pos+1, sum)+go(pos+1, sum+arr[pos]);
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
    	for(int i=0; i<35; i++) dp[i].clear();
    	sf2ll(n, w);


   		for(int i=0; i<n; i++) {
   			sf1ll(arr[i]);
   		}

   		sort(arr, arr+n);

   		long long res=go(0, 0);

   		printf("Case %d: %lld\n", tst++, res);
    }
    return 0;
}