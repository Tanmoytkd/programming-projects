#include <bits/stdc++.h>
using namespace std;
#define mx 200000
int n;
long long arr[mx+7];
int parent[mx];
long long weight[mx+7];
std::vector<int> edge[mx+7];
int subsize[mx+7];

void dfs(int node, int lev) {
	subsize[node]=1;
	level[node]=lev;
	std::vector<int> &e = edge[node];
	for(int i=0; i<e.size(); i++) {
		int next = e[i];
		dfs(next, lev+1);
		subsize[node]+=subsize[next];
	}
}

int chainno=1;
int chainhead[mx+7], chain;
int pos[mx+7];


void hld(int node) {
	if(chainhead[chainno]==0) chainhead[chainno]=node;
	chain[node]=chainno;
	pos[node]=++ipos;

	std::vector<int>& e = edge[node];
	int bigchild = -1;
	for(int i=0; i<e.size(); i++) {
		int next = e[i];
		if(bigchild==-1 || subsize[next]>subsize[bigchild])
			bigchild=next;
	}

	if(bigchild!=-1) hld(bigchild);
	for(int i=0; i<e.size(); i++) {
		int next=e[i];
		if(next==bigchild) continue;
		chainno++;
		hld(next);
	}
}

int tree[mx*4+7], int lazy[mx*4+7];

void update(int node, int start, int fin, int l, int r) {
	int mid = (start+fin)/2;
	int l = node*2;
	int r = l+1;

	if(lazy[node]) {
		if(start!=fin) {
			tree[l]+= (mid-start+1);
			tree[r]+= (fin-mid);
			lazy[l]++;
			lazy[r]++;
		}
		lazy[node]=0;
	}
}

std::vector<long long> v;
std::vector<int> parents;

void qfs(int node, long long totalcost) {
	v.push_back(totalcost);
	parents.push_back(node);
	long long avail = arr[node];

	if(node==1);
	else if(totalcost<=avail) {
		updatenodes(1, parent[node]);
	}
	else {
		int difference = totalcost-avail;
		int pos = lower_bound(v.begin(), v.end(), difference)-v.begin();
		updatenodes(parents[pos], parent[node]);
	}
}

int main() {
	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		scanf("%lld", &arr[i]);
	}

	for(int i=2; i<=n; i++) {
		scanf("%d %lld", &parent[i], &weight[i]);
		edge[parent[i]].push_back(i);
	}

	dfs(1);

	hld(1);

	qfs(1, 0);

	for(int i=1; i<=n; i++) {
		int res = iquery(i);

		if(i!=1) printf(" ");

		printf("%d", res);
	}
	puts("");

	return 0;
}