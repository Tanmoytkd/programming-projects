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

#define mx 1000007

int comp[mx+7];
void sieve() {
	comp[0]=1;
	comp[1] = 1;
	for(int i = 4; i<mx; i+=2) comp[i] = 1;
	for(int i = 3; i*i < mx; i+=2)
	{
		if(comp[i]) continue;
		for(int j = i*i ; j<=mx; j+=i+i) comp[j] = 1;
	}
}

int main() {
	sieve();
	
	int a, b, k;
	sf3(a,b,k);
	
	int l = 0, r = (b-a+1);
	while(l <= r) {
		int mid = (l+r)/2;
		int prm = 0;
		for(int i = a; i<a+mid; i++)
			if(comp[i] == 0) prm++;
		int problem = 0;
		if(prm < k) problem = 1;
		for(int i = a+mid; i <= b; i++){
			prm += (comp[i]==0);
			prm -= (comp[i-mid]==0);
			if(prm < k) {
				problem = 1;
				break;
			}
		}
		if(problem) l = mid + 1;
		else {
			r = mid - 1;
		}
	}
	if(l==b-a+2) cout << "-1" << endl;
	else cout << l << endl;
	return 0;
}
