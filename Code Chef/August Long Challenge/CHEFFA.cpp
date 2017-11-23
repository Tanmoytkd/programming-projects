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
#define mod 1000000007LL
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int n;
vector<int> arr;
long long dp[2500][110][110];

long long go(int p1) {
	int p2=p1+1;
	int v1=arr[p1], v2=arr[p2];
	int endflag=0;

	if(dp[p1][v1][v2]==-1) {
		long long & ret=dp[p1][v1][v2];
		if(p2==arr.size()-1) {
			ret=1;
			int move=min(v1, v2);
			arr.push_back(0);
			for(int i=1; i<=move; i++) {
				arr[p1]=v1-i;
				arr[p2]=v2-i;
				arr[p1+2]++;
				ret+=go(p1+1);
				ret%=mod;
			}

			arr[p1]=v1;
			arr[p2]=v2;
			while(p2+1<arr.size()) arr.pop_back();
		}
		else {
			ret=0;
			int move=min(v1, v2);
			int p3=p1+2, v3=arr[p3];
			for(int i=0; i<=move; i++) {
				arr[p1]=v1-i;
				arr[p2]=v2-i;
				arr[p1+2]=v3+i;
				ret+=go(p1+1);
				ret%=mod;
			}

			arr[p1]=v1;
			arr[p2]=v2;
			arr[p3]=v3;
		}
	}
	return dp[p1][v1][v2];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {	
    	sf1(n);
    	if(n==1) {
    		int num;
    		sf1(num);
    		pf1(1);
    		continue;
    	}
    	memset(dp, -1, sizeof dp);
    	arr.clear();
    	for(int i=0; i<n; i++) {
    		int num;
    		sf1(num);
    		arr.push_back(num);	
    	} 

    	long long res=go(0);
    	res%=mod;

    	printf("%lld\n", res);

    }
    
    return 0;
}