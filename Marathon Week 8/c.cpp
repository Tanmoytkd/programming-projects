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

struct frac {
	long long up, down;
	frac(int x, int y) {
		up=x, down=y;
		long long g = __gcd(up, down);
		if(g!=0) {
			up/=g;
			down/=g;
		}
		if(down<0) {
			down=0-down;
			up=0-up;
		}
	}

	friend bool operator< (const frac a,const frac b);
};

bool operator< (const frac a,const frac b) {
	if(a.up<b.up) return true;
	if(a.up>b.up) return false;
	return a.down>b.down;
}

int main()
{
    int n;
    sf1(n);

    int x[n+1], y[n+1];
    FOR(i, n) sf2(x[i], y[i]);

    map<frac, long long> cnt[n+1];

    FOR(i, n) {
    	FOR(j, n) {
    		if(i==j) continue;
    		int ydif=y[i]-y[j], xdif=x[i]-x[j];
    		// cout << "difference : " << i << " " << ydif << " " << xdif << endl;
    		frac f(ydif, xdif);
    		// cout << f.up << " " << f.down << endl;
    		cnt[i][f]++;
    	}
    }

    // FOR(i, n) cout << "size " << i <<  ": " << cnt[i].size() << endl;
    
    long long res = 0;
    FOR(i, n) {
    	map<frac, long long> & mp = cnt[i];
    	map<frac, long long>::iterator it;


    	int res1=0;
    	long long sum = 0;
    	// cout << x[i] << " " << y[i] << endl;

    	for(it=mp.begin(); it!=mp.end(); it++) {
    		// cout << "ratio " <<  it->first.up << ' ' << it->first.down  << " " << it->second << endl;
    		long long c = it->second;
    		sum+=c;
    		res1+= c*(n-1-sum);
    	}

    	// cout << x[i] << " " << y[i] << " " << res1 << endl;

    	res+=res1;
    }

    cout << res/3 << endl;

    return 0;
}