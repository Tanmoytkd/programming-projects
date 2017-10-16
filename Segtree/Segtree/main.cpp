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


int tree[400], lazy[400];

void update(int node, int start, int fin, int l, int r) {
	int mid=(start+fin)/2;
	int left=node*2, right=left+1;
//
//	if(lazy[node]) {
//		if(start!=fin) {
//			tree[left]+= lazy[node]*(mid-start+1);
//			lazy[left]++;
//
//			tree[right]+=lazy[node]*(fin-mid);
//			lazy[right]++;
//		}
//		lazy[node]=0;
//	}

	if(start>r || fin<l) return;
	if(start>=l && fin<=r) {
		tree[node]+=fin-start+1;
		lazy[node]++;
		return;
	}


    if(start==fin) {
        tree[node]++;
        return;
    }


	update(left, start, mid, l, r);
	update(right, mid+1, fin, l, r);

	tree[node]=tree[left]+tree[right];
}

int query(int node, int start, int fin, int l, int r) {
	int mid=(start+fin)/2;
	int left=node*2, right=left+1;

	if(lazy[node]) {
		if(start!=fin) {
			tree[left]+= lazy[node]*(mid-start+1);
			lazy[left]++;

			tree[right]+=lazy[node]*(fin-mid);
			lazy[right]++;
		}
		lazy[node]=0;
	}

	if(start>r || fin<l) return 0;
	if(start>=l && fin<=r) return tree[node];

	return query(left, start, mid, l, r)+query(right, mid+1, fin, l, r);
}


int main()
{
    update(1, 1, 5, 1, 1);
    update(1, 1, 5, 1, 2);
   	update(1, 1, 5, 1, 3);
    update(1, 1, 5, 1, 4);
    int n=5;
    FOR1(i, n) {
    	if(i!=1) pf(" ");
    	printf("%d", query(1, 1, n, i, i));
    }
    puts("");


    return 0;
}
