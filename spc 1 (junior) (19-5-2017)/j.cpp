#include <bits/stdc++.h>
using namespace std;

int root = 0;
#define N 10100
#define LN 14

vector <int> edge[N], costs[N], indexx[N];
int arr[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], parent[LN][N], otherEnd[N], subsize[N];
int tree[N*4];

void build(int node, int s, int e) {
	if(s == e-1) {
		tree[node] = arr[s];
		return;
	}
	int left = node*2, right = left+1, m = (s+e)/2;
	build(left, s, m);
	build(right, m, e);
	tree[node] = max(tree[left], tree[right]);
}

void update(int node, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		tree[node] = val;
		return;
	}
	int left = node*2, right = left + 1, m = (s+e)/2;
	update(left, s, m, x, val);
	update(right, m, e, x, val);
	tree[node] = max(tree[left], tree[right]);
}

int query(int node, int s, int e, int S, int E) {
	if(s >= E || e <= S) {
		return -1;
	}
	if(s >= S && e <= E) {
		return tree[node];
	}
	int left = node*2, right = left + 1, m = (s+e)/2;
	int res1 = query(left, s, m, S, E);
	int res2 = query(right, m, e, S, E);
	return max(res1, res2);
}

int query_up(int u, int v) {
	if(u == v) return 0;
	int uchain, vchain = chainInd[v], ans = -1;
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			if(u==v) break;
			int res = query(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			if(res > ans) ans = res;
			break;
		}
		int res = query(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
		if(res > ans) ans = res;
		u = chainHead[uchain];
		u = parent[0][u];
	}
	return ans;
}

int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = parent[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(parent[i][u] != parent[i][v]) {
		u = parent[i][u];
		v = parent[i][v];
	}
	return parent[0][u];
}

void iquery(int u, int v) {
	int lca = LCA(u, v);
	int ans = query_up(u, lca);
	int temp = query_up(v, lca);
	if(temp > ans) ans = temp;
	printf("%d\n", ans);
}

void change(int i, int val) {
	int u = otherEnd[i];
	update(1, 0, ptr, posInBase[u], val);
}

void HLD(int curNode, int cost, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode;
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr;
	arr[ptr] = cost;
	ptr++;

	int sc = -1, ncost;
    vector<int>&e = edge[curNode];
    vector<int>&c = costs[curNode];
	for(int i=0; i<e.size(); i++) {
        if(e[i] != prev) {
            if(sc == -1 || subsize[sc] < subsize[e[i]]) {
                sc = e[i];
                ncost = c[i];
            }
        }
	}

	if(sc != -1) {
		HLD(sc, ncost, curNode);
	}

	for(int i=0; i<e.size(); i++) if(e[i] != prev) {
		if(sc != e[i]) {
			chainNo++;
			HLD(e[i], c[i], curNode);
		}
	}
}


void dfs(int node, int prev, int _depth=0) {
	parent[0][node] = prev;
	depth[node] = _depth;
	subsize[node] = 1;
	for(int i=0; i<edge[node].size(); i++)
		if(edge[node][i] != prev) {
			otherEnd[indexx[node][i]] = edge[node][i];
			dfs(edge[node][i], node, _depth+1);
			subsize[node] += subsize[edge[node][i]];
		}
}

int main() {
	int t;
	scanf("%d ", &t);
	while(t--) {
		ptr = 0;
		int n;
		scanf("%d", &n);

		for(int i=0; i<n; i++) {
			edge[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			for(int j=0; j<LN; j++) parent[j][i] = -1;
		}
		for(int i=1; i<n; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			u--;
			v--;
			edge[u].push_back(v);
			costs[u].push_back(c);
			indexx[u].push_back(i-1);
			edge[v].push_back(u);
			costs[v].push_back(c);
			indexx[v].push_back(i-1);
		}

		chainNo = 0;
		dfs(root, -1);
		HLD(root, -1, -1);
		build(1, 0, ptr);


		for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(parent[i-1][j] != -1)
					parent[i][j] = parent[i-1][parent[i-1][j]];

		while(1) {
			char s[100];
			scanf("%s", s);
			if(s[0]=='D') {
				break;
			}
			int a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='Q') {
				iquery(a-1, b-1);
			}
			else {
				change(a-1, b);
			}
		}
	}
}
