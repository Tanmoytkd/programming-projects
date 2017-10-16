#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
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

#define mx 200007
long long a[mx], w[mx];
int chainno, lazy[mx*4], tree[mx*4], p[mx], chainInd[mx], index[mx], n, chainHead[mx], arrsize[mx], pos, chainpos[mx], chainsize[mx];
std::vector<pair<int, int > > updates;
std::vector<int> v, edge[mx];
std::vector<lint>  sum;

void hld(int node) {
	index[node]=++pos;
	if(chainHead[chainno]==0) chainHead[chainno]=node;

	chainInd[node]=chainno;
	chainpos[node]=chainsize[chainno];
	chainsize[chainno]++;

	int ind=-1, mai=-1;
	std::vector<int>& e = edge[node];
	FOR(i, e.size()) {
		if(arrsize[e[i]]>mai) {
			mai=arrsize[e[i]];
			ind=i;
		}
	}

	if(ind>=0) hld(e[ind]);

	FOR(i, e.size()) {
		if(i!=ind) {
			chainno++;
			hld(e[i]);
		}
	}
}

int dfs(int node, long long dist) {
	arrsize[node]=1;
	v.pb(node);
	sum.pb(dist);

	if(node!=1) {
		if(dist>a[node]){
			lint diff = dist - a[node];
			int ipos = lower_bound(sum.begin(), sum.end(), diff) - sum.begin();
			
			if(ipos!=sum.size()-1) {

				updates.pb(make_pair(v[ipos], p[node]));
			}
		}
		else {
			updates.pb(make_pair(1, p[node]));
		}
	}
	// if(i<=j && i>=0) {
	// 	updates.pb(make_pair(v[i], v[j]));
	// }

	std::vector<int>&  e = edge[node];
	FOR(i, e.size()) {
		int nxt = e[i];
		arrsize[node]+=dfs(nxt, dist+w[nxt]);	
	}

	sum.ppb();
	v.ppb();
	return arrsize[node];
}

void update(int node, int start, int fin, int l, int r) {
	if(l>r) return;
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
	
	if(start>r || fin<l) return;
	if(start>=l && fin<=r) {
		tree[node]+=fin-start+1;
		lazy[node]++;
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


void upd(int l, int r) {
	int lchain = chainInd[l], rchain = chainInd[r];
	while(1) {
		if(lchain==rchain) {
			// //cout << l << " " << r << endl;
			//cout << index[chainHead[rchain]] << " " << index[r] << endl;

			update(1, 1, n, index[l], index[r]);
			break;
		}
		//cout << chainHead[rchain] << " " << r << endl;
		update(1, 1, n, index[chainHead[rchain]], index[r]);
		
		r=chainHead[rchain];
		r=p[r];
		rchain=chainInd[r];
	}
}




int main()
{
    sf1(n);
    FOR1(i, n) sf1ll(a[i]);

    for(int i=2; i<=n; i++) {
    	sf1(p[i]);
    	sf1ll(w[i]);
    	edge[p[i]].pb(i);
    }

    dfs(1, 0);
    hld(1);

    for(int i=0; i<updates.size(); i++) {
    	pair<int, int> range = updates[i];
    	////cout << range.fs << " " << range.sc << endl;
    	upd(range.fs, range.sc);
    
    	// FOR1(i, n) {
	    // 	if(i!=1) pf(" ");
	    // 	printf("%d", query(1, 1, n, index[i], index[i]));
	    // }
	    // puts("");

    }

    FOR1(i, n) {
    	if(i!=1) pf(" ");
    	printf("%d", query(1, 1, n, index[i], index[i]));
    }
    puts("");

    return 0;
}

