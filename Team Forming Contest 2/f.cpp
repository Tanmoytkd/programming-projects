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
#define mod 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
#define mx 50000
long long arr[mx+7], tree[mx*4+7];

void build(int node, int start, int fin) {
	if(start==fin) {
		tree[node]=arr[start]%mod;
		return;
	}

	int mid=(start+fin)/2;
	int left=node*2, right=left+1;

	build(left, start, mid);
	build(right, mid+1, fin);

	tree[node]=(tree[left]*tree[right])%mod;
}


void update(int node, int start, int fin, int l, int r, int val) {
	if(start>r || fin<l) return;
	if(start>=l && fin<=r) {
		tree[node]=val%mod;
		return;
	}

	int mid=(start+fin)/2;
	int left=node*2, right=left+1;

	update(left, start, mid, l, r, val);
	update(right, mid+1, fin, l, r, val);

	tree[node]=(tree[left]*tree[right])%mod;
}

long long query(int node, int start, int fin, int l, int r) {
	if(start>r || fin<l) return 1;
	if(start>=l && fin<=r) return tree[node];

	int mid=(start+fin)/2;
	int left=node*2, right=left+1;

	return (query(left, start, mid, l, r) * query(right, mid+1, fin, l, r))%mod;
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
    	int n;
    	sf1(n);
    	FOR1(i, n) sf1ll(arr[i]);
    	
    	build(1, 1, n);

    	int q;
    	sf1(q);

    	while(q--) {
	    	int action, l, r;
	    	sf3(action, l, r);
	    	if(action) update(1, 1, n, l, l, r);
	    	else {
	    		pf("%lld\n", query(1, 1, n, l, r));
	    	}
    	}
    }
    return 0;
}