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

int cmp(pair<int, int> a, pair<int, int> b) {
	int dig1=a.fs+a.sc, dig2=b.fs+b.sc;
	if(dig1==dig2) return a.sc<b.sc;
	return dig1<dig2;
}

int main()
{
    int t, tst = 1;
	int n;
	sf1(n);
	std::vector<pair<int, int> > v;
	int scount=0;
	while(scount*7<=n) {
		if((n-scount*7)%4==0) {
			int fcount = (n-scount*7)/4;
			v.pb(make_pair(fcount, scount));
		}
		scount++;
	}

	if(v.size()==0)
		puts("-1");
	else {
		sort(v.begin(), v.end(), cmp);
		int fcount=v[0].first, scount=v[0].second;
		FOR(i, fcount) printf("4");
		FOR(i, scount) printf("7");
		puts("");
	}
    return 0;

}