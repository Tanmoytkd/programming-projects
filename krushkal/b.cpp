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

long long a[100007];

int main()
{
    int t, tst = 1;
 	sf1(t);
 	while(t--) {
 		lint n, m, p, q, r, x, y, z;
 		sf2ll(n, m);
 		sf3ll(p, q, r);
 		sf3ll(x, y, z);

 		char small[n+1];

 		memset(small, 0, sizeof small);

 		FOR1(i, m) small[(x*i*i+y*i+z)%n+1] = 1;

 		long long root = -1;
 		FOR1(i, n) {
 			a[i] = (p*i*i + q*i + r) % 1000007;
 			if(!small[i] && (root==-1 || a[i]<=a[root])) {
 				root=i;
 			}
 		}

 		long long res = 0;
 		FOR1(i, n) {
 			if(i==root) continue;
 			res+=a[i]*a[root];
 		}
 		pf("Case %d: %lld\n", tst++, res);

 	}   
    return 0;
}