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
#define mx 100007

int arr[mx];
vector<int> tree[mx*4];

void build(int node, int start, int fin) {
	// //cout << "Node " << node << " start " << start << " fin " << fin << endl;
	tree[node].clear();

	if(start==fin) {
		tree[node].pb(arr[start]);
		return;
	}

	int mid = (start+fin)/2;
	int left = node*2, right = left+1;

	build(left, start, mid);
	build(right, mid+1, fin);

	merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

int query(int node, int start, int fin, int l, int r, int val) {
	if(start>r || fin<l) return 0;
	if(start>=l && fin<=r) {
		return upper_bound(tree[node].begin(), tree[node].end(), val)-tree[node].begin();
	}

	int mid = (start+fin)/2;
	int left=node*2, right = left+1;

	return query(left, start, mid, l, r, val)+query(right, mid+1, fin, l, r, val);
}

int main()
{
    int t, tst = 1;
	sf1(t);
	FOR1(tst, t) {
		int n, m;
		sf2(n, m);

		FOR1(i, n) {
			sf1(arr[i]);
			//cout << arr[i] << endl;
		}

		// //cout << "start" << endl;
		build(1, 1, n);
		// //cout << "end" << endl;
		pf("Case %d:\n", tst);
		while(m--) {
			int l, r, h;
			sf3(l, r, h);

			pf("%d\n", query(1, 1, n, l+1, r+1, h));
		}

	}
    return 0;
}