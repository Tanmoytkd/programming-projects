#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int color[200007], mark[200007], used[200007], cnt[200007];
int same=0, total=0;
vector<int> edge[200007];
set<int> colors;

void dfs(int node) {
	mark[node]=1;
	int col = color[node];
	colors.insert(col);
	cnt[col]++;
	total++;
	same=max(same, cnt[col]);

	vector<int> & e = edge[node];

	for(int i=0; i<e.size(); i++) {
		int nxt = e[i];
		if(mark[nxt]) continue;
		dfs(nxt);
	}
}

int main() {
	
	scanf("%d%d%d", &n, &m, &k);

	//cout << n << " " << m << " " << k << endl;

	for(int i=1; i<=n; i++) {
		scanf("%d", &color[i]);
	}

	for(int i=1; i<=m; i++) {
		
		int l, r;
		scanf("%d%d", &l, &r);
		
		used[l]=used[r]=1;
		edge[l].push_back(r);
		edge[r].push_back(l);
	}

	//cout << "TKD" << endl;

	int res = 0;

	for(int i=1; i<=n; i++) {
		if(mark[i] || (used[i]==0)) continue;

		dfs(i);

		res += total-same;

		for(set<int>::iterator it = colors.begin(); it!=colors.end(); it++) {
			cnt[*it]=0;
		}
		colors.clear();
		total=0;
		same=0;

	}

	cout << res << endl;


	return 0;
}