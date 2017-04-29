/*input
1
1 1
*/
#include<bits/stdc++.h>
#define pii pair<lint,lint>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%lld\n",a)
#define hi() printf("hi!\n")
#define sf scanf
#define sf1(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %lld: ",x)
#define mod  1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(lint i=0;i<(x); i++)
#define FOR1(i, x) for(lint i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

lint bigmod(lint a, lint p, lint m=mod) {
	if(p==0) return 1%m;
	if(p&1) return ((a%m)*bigmod(a, p-1, m))%m;
	lint ret=bigmod(a, p/2, m);
	ret*=ret;
	return ret%m;
}


int main()
{
    lint t, tst = 1;
	cin >> t;
	while(t--) {
		lint n, k;
		cin >> n >> k;

		lint res=0;
		FOR1(i, n) {
			res+= bigmod(k, __gcd(i, n), mod);
			res%=mod;
		}

		res*=bigmod(n, mod-2, mod);
		res%=mod;
		pcase(tst++);
		cout << res << endl;
	}
    return 0;
}
