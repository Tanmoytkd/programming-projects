#include <bits/stdc++.h>
using namespace std;
#define mx 100007

int n;
vector<int> tree[4*mx];
int arr[mx];

void clear(int node, int start, int fin) {
	if(node<4*mx) tree[node].clear(); //prob
	if(start==fin) return;

	int mid = (start+fin)/2;
	int left = node*2;
	int right = left+1;

	clear(left, start, mid);
	clear(right, mid+1, fin);
}

void print(vector<int> & v) {
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";

	}
	cout << endl;
}

void build(int node, int start, int fin) {
	if(start==fin) {
		tree[node].push_back(arr[start]);
		// cout << "NOde " << node << ": ";
		// print(tree[node]);
		return;
	}

	int mid = (start+fin)/2;
	int left = node*2;
	int right = left+1;

	build(left, start, mid);
	build(right, mid+1, fin);

	merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
	
	// cout << "NOde " << node << ": ";
	// print(tree[node]);
	
}

long long query(int node, int start, int fin, int l, int r) {
	if(start>r || fin<l) return 0;

	long long val = (arr[l]+arr[r])/2;
	int mid = (start+fin)/2;
	int left = node*2;
	int right = left+1;
	long long d = llabs(arr[l]-arr[r]); //l>r

	if(start>=l && fin<=r) {
		vector<int> & v = tree[node];
		int pos = lower_bound(v.begin(), v.end(), val) - v.begin();
		long long res=0;
		for(int diff=-2; diff<=2; diff++) {
			int index = pos+diff;
			if(index>=0 && index<v.size()) { //lessthanequalto problems
				long long x = v[index]-arr[l];
				x*=arr[r]-v[index];
				res=max(res, x);
			} 
		}
		return res;
	}

	long long res1 = query(left, start, mid, l, r);
	long long res2 = query(right, mid+1, fin, l, r);

	return max(res1, res2);
}

void update(int node, int start, int fin, int l, int r, int origin, int latest) {
	if(start>r || fin<l) return;

	int mid = (start+fin)/2;
	int left = node*2;
	int right = left+1;

	vector<int> & v = tree[node];
	if(latest>origin && binary_search(v.begin(), v.end(), origin)) {
		int pos = (upper_bound(v.begin(), v.end(), origin) - v.begin())-1;
		v[pos]=latest;
	}
	else if(latest<=origin && binary_search(v.begin(), v.end(), origin)) {
		int pos = lower_bound(v.begin(), v.end(), origin) - v.begin();
		v[pos]=latest;
	}

	if(start==fin) return;
	update(left, start, mid, l, r, origin, latest);
	update(right, mid+1, fin, l, r, origin, latest);
}

void realupdate(int index, int val) {
	update(1, 1, n, index, index, arr[index], val);
	arr[index]=val;
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int q;
		scanf("%d %d", &n, &q);
		for(int i=1; i<=n; i++) {
			scanf("%d", &arr[i]);
		}

		build(1, 1, n);

		while(q--) {
			int type;
			scanf("%d", &type);

			if(type==1) {
				int l, r;
				scanf(" %d %d", &l, &r);
				long long res = query(1, 1, n, l, r);
				printf("%lld\n", res);
			}
			else {
				int x, y;
				scanf(" %d %d", &x, &y);
				realupdate(x, y);
			}
		}

		clear(1, 1, n);
	}
	return 0;
}