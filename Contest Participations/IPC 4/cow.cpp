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
#define pii pair<int, int> 
#define N 1007
int n, m, x;

int fordist[N], revdist[N], formark[N], revmark[N];
vector<int> foredge[N], revedge[N], forcost[N], revcost[N];


void dijkstra(int dist[], int mark[], vector<int>edge[], vector<int>cost[], int start) {
	dist[start]=0;
	priority_queue< pii, vector< pii >, greater< pii > > pq;
	pq.push(pii(0, start));

	while(!pq.empty()) {
		int node = pq.top().second;
		int icost = pq.top().first;
		pq.pop();
		if(mark[node]) continue;
		mark[node]=1;

		vector<int> & e = edge[node];
		vector<int> & c = cost[node];
		for(int i=0; i<e.size(); i++) {
			int nxt = e[i];
			int cst = c[i];

			if(mark[nxt]) continue;

			if(dist[node]<dist[nxt]-cst) {
				dist[nxt] = dist[node]+cst;
				pq.push(pii(dist[nxt], nxt));
			}
		}

	}
}

int main() {
	
	scanf("%d%d%d", &n, &m, &x);

	for(int i=0; i<=n; i++) {
		fordist[i]=INT_MAX;
		revdist[i]=INT_MAX;
	}

	memset(formark, 0, sizeof formark);
	memset(revmark, 0, sizeof revmark);

	for(int i=0; i<m; i++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);

		foredge[a].push_back(b);
		forcost[a].push_back(t);

		revedge[b].push_back(a);
		revcost[b].push_back(t);
	}

	dijkstra(fordist, formark, foredge, forcost, x);
	dijkstra(revdist, revmark, revedge, revcost, x);

	long long maxtime = 0;
	for(int i=1; i<=n; i++) {
		maxtime = max( (long long) fordist[i]+revdist[i], maxtime);
	}

	printf("%lld\n", maxtime);

	return 0;
}