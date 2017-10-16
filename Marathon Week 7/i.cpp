#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d",a)
#define pf1ll(a) printf("%lld\n", a)
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


int color[200007], par[200007];

std::vector<int> prob, root;

int n;

void go(int node) {
	if(color[node]==2) return;
	if(par[node]==node) {
		root.pb(node);
		color[node]=2;
		return;
	}
	color[node]++;
	int next= par[node];
	if(color[next]==1) {
		prob.pb(node);
	}
	else {
		go(next);
	}

	color[node]++;
}

int main() {
	sf1(n);
	for(int i=1; i<=n; i++) {
		sf1(par[i]);
	}

	for(int i=1; i<=n; i++) {
		go(i);
	}

	int minmove=0;
	minmove+=prob.size();
	if(!root.empty()) minmove+=root.size()-1;

	if(minmove) {
		int nxtroot;
		if(!prob.empty()) nxtroot=prob[0];
		if(!root.empty()) nxtroot=root[0];

		for(int i=0; i<prob.size(); i++) {
			int node=prob[i];
			par[node]=nxtroot;
		}
		for(int i=0; i<root.size(); i++) {
			int node=root[i];
			par[node]=nxtroot;
		}
	}
	
	pf1(minmove);
	puts("");
	for(int i=1; i<=n; i++) {
		if(i!=1) pf(" ");
		pf1(par[i]);
	}
	puts("");
	return 0;
}