#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int n;
	std::vector<int> par, rank;

	DSU() = delete;
	DSU(int n): n(n), par(n+1), rank(n+1) {
		for(int i=0; i<=n; i++) {
			par[i]=i;
			rank[i]=1;
		}
	}

	int parent(int a) {
		if(par[a]==a) return par[a];
		par[a]=parent(par[a]);
		return par[a];
	}

	int connected(int a, int b) {
		if(parent(a)==parent(b)) return 1;
		return 0;
	}

	int connect(int a, int b) {
		int made_connection=0;
		if(a==b) return 0;
		if(par[a]!=a || par[b]!=b) made_connection = connect(par[a], par[b]);
		else {
			made_connection=1;
			if(rank[a]>=rank[b]) par[b]=a;
			else par[a]=b;
			if(rank[a]==rank[b]) rank[a]++;
		}

		if(made_connection) {
			par[a]=par[par[a]];
			par[b]=par[par[b]];
		}

		return made_connection;
	}
};

int main() {
	std::vector<DSU> v(5, 10); //create 5 DSU each initialized with 10
	return 0;
}