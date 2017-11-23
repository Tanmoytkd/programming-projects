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
#define mx 20000
int arr[mx+7], tree[4*(mx+7)];


void build(int node, int start, int fin) {
	if(start==fin) {
		tree[node]=arr[start];
		return;
	}

	int mid=(start+fin)/2;
	int left=node*2, right=left+1;

	build(left, start, mid);
	build(right, mid+1, fin);

	tree[node]=tree[left]&tree[right];
}

int query(int node, int start, int fin, int l, int r) {
	if(start>r || fin<l) return -1;
	if(start>=l && fin<=r) return tree[node];

	int mid=(start+fin)/2;
	int left=node*2, right=left+1;

	return query(left, start, mid, l, r) & query(right, mid+1, fin, l, r);	
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
    	int n, k;
    	sf2(n, k);
    	for(int i=1; i<=n; i++) {
    		sf1(arr[i]);
    	}
    	if(k>(n-1)/2) {
    		long long res=-1;
    		for(int i=1; i<=n; i++) res&=arr[i];
    		printf("%d", res);
    		for(int i=0; i<n-1; i++) printf(" %d", res);
    		puts("");
    		continue;
    	}

    	build(1, 1, n);

    	for(int i=1; i<=n; i++) {
    		int res1, res2;
    		int l=i-k;
    		if(l>0) res1=query(1, 1, n, l, i);
    		else res1=query(1, 1, n, l+n, n) & query(1, 1, n, 1, i);

    		int r=i+k;
    		if(r<=n) res2=query(1, 1, n, i, r);
    		else res2=query(1, 1, n, i, n) & query(1, 1, n, 1, r-n);
    		
    		int res=res1 & res2;
    		if(i!=1) pf(" ");
    		pf("%d", res);
    	}
    	puts("");
    }
    return 0;
}