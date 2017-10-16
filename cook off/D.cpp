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
    int t, tst = 1;
    sf1(t);
    while(t--) {
    	long long n, x1, x2, y1, y2;
    	sf3ll(n, x1, y1);
    	sf2ll(x2, y2);

	
		long long left1=y1-1, left2=y2-1;
		long long right1=n-y1, right2=n-y2;
		int lc1=0, lc2=0;
		long long dist1, dist2;
    	if(left1<=right1) {
    		lc1=1;
    		dist1=left1;
    	}
    	else {
    		dist1=right1;
    	}

    	if(left2<=right2) {
    		lc2=1;
    		dist2=left2;
    	}
    	else {
    		dist2=right2;
    	}
    	// cout << lc1 << lc2 << endl;
    	// cout << dist1 << " " << dist2 << endl;

    	if(x1==x2) {
    		// cout << "poka" << endl;
    		if(lc1==lc2) {
    			if(dist1<dist2) {
    				cout << "Slava" << endl;
    				continue;
    			}
    			else {
    				cout << "Miron" << endl;
    				continue;
    			}
    		}
    		if(n%2==0) {
    			if(dist1==dist2 || dist1+1==dist2) cout << "Draw" << endl;
    			else if(dist1>dist2) cout << "Miron" << endl;
    			else cout << "Slava" << endl;
    			continue;
    		}	
    		else {
    			if(dist1==dist2) cout << "Draw" << endl;
    			else if(dist1>dist2) cout << "Miron" << endl;
    			else cout << "Slava" << endl;
    			continue;
    		}
    	}
    	else {
    		//cout << "loka" << endl;
    		if(lc1==lc2) {
    			//cout << "pota" << endl;
    			if(y1==y2) cout << "Draw" << endl;
    			else if(dist1>dist2) cout << "Miron" << endl;
    			else if(dist1+1==dist2) cout << "Draw" << endl;
    			else cout << "Slava" << endl;
    			continue;
    		}
    		if(n%2==0) {
    			if(dist1==dist2) cout << "Draw" << endl;
    			else if(dist1>dist2 && dist1-dist2==1) cout << "Draw" << endl;
    			else if(dist1>dist2) cout << "Miron" << endl;
    			else cout << "Slava" << endl;
    			continue;
    		}
    		else {
    			if(dist1==dist2) cout << "Draw" << endl;
    			else if(dist1>dist2) cout << "Miron" << endl;
    			else cout << "Slava" << endl;
    			continue;
    		}
    	}
    }
    return 0;
}