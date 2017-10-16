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
typedef double dbl;
#define mx 1000000

int n, m;
int ara[20];
std::vector<int> divisor[20];

int dp[132000];

#define check(num, x) ((num>>x)&1)
#define set(num, x) (num|(1<<x))
#define clr(num, x) (num&(~(1<<x)))

int rec(int mask) {
	bitset<20> bt(mask);
	//cout << bt << endl;
	if(__builtin_popcount(mask)==n) return 0;
	if(dp[mask]==-1) {
		int pos=0;
		while(check(mask, pos)) pos++;

		int value  = ara[pos];
		std::vector<int>& v = divisor[pos];

		int & ret = dp[mask];
		ret = INT_MAX;

		for(int i=0; i<v.size(); i++) {
			int newmask = mask;
			int d = v[i];
			////cout << value << " " << d << endl;
			for(int j=0; j<n; j++) {
				//cout << ara[j] << " ";
				if(ara[j]%d==0) { 
					newmask = set(newmask, j);
					////cout << d <<" " << newmask << endl;
				}
			}
			ret = min(ret, (m/d)+rec(newmask));
		}
	}
	return dp[mask];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
    	
    	sf2(n, m);


    	FOR(i, n) {
			sf1(ara[i]);
			divisor[i].clear();
			int num = ara[i];
			int stop = sqrt(num);
			for(int j=1; j<=stop; j++) {
				if(num%j==0) {
					divisor[i].push_back(j);
					if((j*j)!=num) divisor[i].push_back(num/j);
				}
			}
    	}

    	memset(dp, -1, sizeof dp);

    	int res = rec(0);
    	pf("Case %d: %d\n", tst++, res);
    	//cout << res << endl;
    }
    return 0;
}