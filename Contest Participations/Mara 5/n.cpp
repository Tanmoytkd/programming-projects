/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}
int seen[30000], deen[30000], idepth[30000];
vector<int> edge[30000], icost[30000];

bool func(int a, int b) {
    return a>b;
}

int mxdpt(int src) {
    if(idepth[src]==-1) {
        deen[src]=1;

        vector<int> &e = edge[src];
        vector<int> &cost = icost[src];

        vector<int> depth;
        depth.pb(0);
        depth.pb(0);

        FOR(i, e.size()) {
            if(deen[e[i]]) continue;
            depth.pb(cost[i]+mxdpt(e[i]));
        }
        sort(depth.begin(), depth.end(), func);
        idepth[src]=depth[0];
    }
    deen[src]=0;
    return idepth[src];

}

int d(int src) {
    int imax=0;
    seen[src]=1;
    deen[src]=1;

    vector<int> & e= edge[src];
    vector<int> & cost = icost[src];

    FOR(i, e.size()) {
        if(seen[e[i]]) continue;
        imax = max(imax, d(e[i]) );
    }

    vector<int> depth;
    depth.pb(0);
    depth.pb(0);
    FOR(i, e.size()) {
        if(deen[e[i]]) continue;

        depth.pb(cost[i]+mxdpt(e[i]));
    }

    sort(depth.begin(), depth.end(), func);

    imax = max(imax, depth[0]+depth[1]);
    return imax;
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int t;
    sf1(t);
    FOR1(test, t) {
        int n;
        sf1(n);

        memset(seen, 0, sizeof seen);
        memset(deen, 0, sizeof deen);
        memset(idepth, -1, sizeof idepth);
        vector<int> dump;
        FOR(i, n) {
            edge[i]=dump;
            icost[i]=dump;
        }

        FOR(i, n-1) {
            int u, v, w;
            sf3(u,v,w);

            edge[u].pb(v);
            icost[u].pb(w);
            edge[v].pb(u);
            icost[v].pb(w);
        }

        pf("Case %d: %d\n", test, d(0));
    }
    return 0;
}
