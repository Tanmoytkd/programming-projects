#include <bits/stdc++.h>
using namespace std;
#define lint long long

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
    lint n, k;
    scanf("%lld%lld", &n, &k);
    lint arr[n+7];
    lint sum=0;
    for(int i=1; i<=n; i++) {
        scanf("%lld", &arr[i]);
        sum+=arr[i];
    }

    DSU d(n+7);

    while(k--) {
        int action;
        scanf("%d", &action);
        if(action==2) printf("%lld\n", sum);
        else {
            long long u, v;
            scanf("%lld%lld", &u, &v);

            int p1=d.parent(u);
            int p2=d.parent(v);
            int check = d.connect(u, v);
            int p3 = d.parent(u);
            if(check) sum-=min(arr[p1], arr[p2]);
            arr[p3] = max(arr[p1], arr[p2]);

        }
    }
    return 0;
}
