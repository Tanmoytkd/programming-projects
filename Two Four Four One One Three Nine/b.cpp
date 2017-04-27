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

struct krushkal {
	int sum=0;
	int n;
	DSU d;
	std::vector<pair<int, pair<int, int> > > edge, res;

	krushkal(int n): n(n), d(n) {}

	void addEdge(int a, int b, int cost) {
		// edge.push_back(make_pair(cost, make_pair(a,b)));
		edge.push_back({cost, {a,b}}); //making pair using initializer list
	}

	int calculate_mst() {
		res.clear();
		sum=0;
		sort(edge.begin(), edge.end());
		for(int i=0; i<edge.size(); i++) {
			pair<int, int> e = edge[i].second;

			int a=e.first, b=e.second;

			if(d.connected(a, b)) continue;
			sum+=edge[i].first;
			d.connect(a,b);
		}
		return sum;
	}
};

int main() {
    int t;
    cin >> t;

    while(t--) {
        int p, n, m;
        cin >> p >> n >> m;
        krushkal k(n);
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            k.addEdge(a,b,c);
        }

        int res = k.calculate_mst();
        cout << res*p << endl;
    }
    return 0;
}
