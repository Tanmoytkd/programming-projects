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

int valid(long long n, long long move) {
	if(n<(move*4)) return 0;
	if(n%(move*4)<move) return 0;
	if(n%(move*4)>=(move*2)) return 0;
	return 1;
}

long long go(long long n) {
		long long ret = 0;
		int mark[70]={0};

		for(long long move=1; move<=n/4; move*=2) {
			if(valid(n, move)) mark[go(n+move)]=1;
		}
		while(mark[ret]) ret++;
		return ret;
}

int main() {
	int t;
	sf1(t);
	while(t--) {
		long long n;
		sf1ll(n);
		// for(n=0; n<=1000; n++) {
		// 	cout << n << ": ";
			long long res=go(n);
			if(res) puts("Meena");
			else puts("Dipu");	
		// }
		
	}
	return 0;
}