#include <bits/stdc++.h>
using namespace std;

long long visit[100007], gold[100007];
vector<long long> edge[100007];


long long dfs(long long player) {
	if(visit[player]) return 0;
	visit[player]=1;

	vector<long long> & e = edge[player];
	long long res = gold[player];
	for(long long i=0; i<e.size(); i++) {
		long long nextplayer = e[i];
		if(visit[nextplayer]) continue;
		res = min(res, dfs(nextplayer));
	}

	return res;
}


int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);

	//cout << n << " " << m << endl;
	for(long long i=1; i<=n; i++) scanf("%lld", &gold[i]);
	for(long long i=1; i<=m; i++) {
		long long u, v;
		scanf("%lld %lld", &u, &v);

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	long long res=0;
	for(long long i=1; i<=n; i++) {
		long long add=dfs(i);
		//cout << add << endl;
		res+=add;
	}

	printf("%I64d\n", res);
}