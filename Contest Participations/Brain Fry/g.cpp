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


int main()
{

	long long n, m;
	cin >> n >> m;
	long long stop=sqrt(m);
	int problem=0;
	for(long long i=2; i<=stop; i++) {
		if(m%i==0 && n>=i) {
			m=m/i;
			n=n-i;
		}
		if(m%i==0) {
			problem=1;
			break;
		}

	}
	// cout << "n: " << n << "  m : " << m << endl;
	if(!problem && (m>1) && (n>=m)) {
		long long i=m;
		m=m/i;
		n=n-i;		
	}
	cout << n << " " << m << endl;
    return 0;
}