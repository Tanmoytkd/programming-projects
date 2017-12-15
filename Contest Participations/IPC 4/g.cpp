#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits.h>

using namespace std;
#define N 100007
#define level 18 
long long n;
vector<long long> edge[N], cost[N];
long long dist[N], parent[N][level], depth[N];

void dfs(long long node, long long currentparent, long long dst) {
	if(node==0) depth[node]=0;
	else depth[node]=depth[currentparent]+1;

	//cout << node << " " << currentparent << " parentcall " << endl;

	parent[node][0]=currentparent;


	dist[node]=dst;
	std::vector<long long> & e = edge[node];
	std::vector<long long> & c = cost[node];
	for(long long i=0; i<e.size(); i++) {
		long long nxt=e[i];
		if(nxt==currentparent) continue;
		dfs(nxt, node, dst+c[i]);
	}
}

void preprocess() {
	for (long long i=1; i<level; i++) {
		for (long long node = 1; node <= n; node++) {
			if (parent[node][i-1] != -1) {
				parent[node][i] = parent[parent[node][i-1]][i-1];
			}
		}
	}
}


long long LCA(long long u, long long v)
{
	//cout << "depth of " << u << " " << depth[u] << endl;
	//cout << "depth of " << v << " " << depth[v] << endl;
	if (depth[v] < depth[u])
		swap(u, v);

	long long diff = depth[v] - depth[u];

	
	for (long long i=0; i<level; i++)
		if ((diff>>i)&1)
			v = parent[v][i];

	
	//cout << u << " " << v << " u v final" << endl;

	if (u == v)
		return u;

	
	for (long long i=level-1; i>=0; i--)
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}

	//cout << u << " " << v << " uv morefinal" << endl;


	return parent[u][0];
}



int main() {
	while(scanf("%lld", &n)==1 && n) {
		for(long long i=0; i<n; i++) {
			edge[i].clear();
			cost[i].clear();
		}

		for(long long i=1; i<n; i++) {
			long long u=i, v;
			scanf("%lld", &v);
			long long l;
			scanf("%lld", &l);

			edge[u].push_back(v);
			cost[u].push_back(l);
			edge[v].push_back(u);
			cost[v].push_back(l);
		}

		memset(parent, -1, sizeof parent);
		dfs(0, -1, 0);

		

		preprocess();

		long long q;
		scanf("%lld", &q);

		while(q--) {
			long long a, b;
			scanf(" %lld %lld", &a, &b);
			long long lca = LCA(a, b);

			//cout << a << " " << dist[a] << endl;
			//cout << b << " " << dist[b] << endl;
			//cout << lca << " " << dist[lca] << endl;

			long long res = dist[a]+dist[b]-2*dist[lca];
			printf("%lld%c", res, " \n"[q==0]);
		}
	}
}