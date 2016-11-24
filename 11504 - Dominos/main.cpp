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

#define mx 1000007

int beg[mx], fin[mx], color[mx];
int itime=0, cnt=0;
vector<int> edge[mx];

struct node {
    int val;
    int beg, fin;
} dom[mx];

bool func(node a, node b) {
    return a.fin>b.fin;
}

void dfs(int v) {
    dom[v].beg=itime++;
    color[v]++;
    vector<int> &e =  edge[v];

    FOR(i, e.size()) {
        int child=e[i];
        if(color[child]==0) {
            dfs(child);
        }
    }
    color[v]++;
    dom[v].fin=itime++;
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int t;
    sf1(t);
    while(t--) {
        int n, m;
        sf2(n, m);
        cnt=0;

        memset(beg, 0, sizeof beg);
        memset(fin, 0, sizeof fin);
        memset(color, 0, sizeof color);
        itime=0;

        FOR1(i, n) dom[i].val=i;

        vector<int> v;
        FOR1(i, n) {
            edge[i]=v;
        }

        while(m--) {
            int x, y;
            sf2(x, y);

            edge[x].pb(y);
        }

        FOR1(i, n) {
            if(color[i]==0) {
                dfs(i);
            }
        }

        sort(dom+1, dom+n+1, func);

        memset(color, 0, sizeof color);

        FOR1(i, n) {
            int d=dom[i].val;
            if(color[d]==0) {
                cnt++;
                dfs(d);
            }
        }

        pf1(cnt);
    }
    return 0;
}
