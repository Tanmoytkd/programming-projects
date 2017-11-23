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

int cnt[300007], color[300007];

int main() {
    //ios::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);
    int N=n-1;
    //cin >> n >> m;
    DSU d(m+7);
    while(n--) {
        int si;
        scanf("%d", &si);
//        cin >> si;
        if(si==0) continue;

        int ice;
        scanf("%d", &ice);
        for(int i=1; i<si; i++) {
            int ice2;
            scanf("%d", &ice2);

            d.connect(ice, ice2);
        }
    }

    while(N--) {
        int a, b;
        scanf("%d%d", &a, &b);
    }

    int mx=0;
    if(m!=0) mx=1;

    for(int i=1; i<=m; i++) {
        int par=d.parent(i);
        color[i]=cnt[par]+1;
        cnt[par]++;
        mx=max(mx, cnt[par]);
    }

    printf("%d\n", mx);
    for(int i=1; i<=m; i++) {
        if(i!=1) printf(" ");
        printf("%d", color[i]);
    }
    printf("\n");

	return 0;
}
