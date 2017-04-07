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

#define mx 1000007

int color[mx];
int cnt=0;
vector<int> edge[mx];

void dfs(int v) {
    vector<int> &e =  edge[v];
    FOR(i, e.size()) {
        int child=e[i];
        if(color[child]==2) {
        	color[child]=1;
        	cnt--;
        }
        if(color[child]==0) {
        	color[child]=1;
            dfs(child);
        }
    }
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    sf1(t);
    while(t--) {
        int n, m;
        sf2(n, m);
        cnt=0;

        memset(color, 0, sizeof color);

        FOR1(i, n)
        	edge[i].clear();

        while(m--) {
            int x, y;
            sf2(x, y);

            edge[x].pb(y);
        }

        FOR1(i, n) {
            if(color[i]==0) {
            	color[i]=2;
            	cnt++;
                dfs(i);
            }
        }

        pf1(cnt);
    }
    return 0;
}
