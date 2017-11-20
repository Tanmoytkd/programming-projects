#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int low[2500], visit[2500], start[2500], fin[2500];
int n, m;
int timer=0;
vector<int> edge[2500];

void dfs(int node, int parent) {
    visit[node]=1;
    start[node]=timer++;
    low[node]=start[node];

    vector<int> & e = edge[node];
    FOR(i, e.size()) {
        int newnode = e[i];
        if(newnode==parent) continue;
        if(visit[newnode]) {
            low[node]=min(low[node], low[newnode]);
            continue;
        }
        else {
            dfs(newnode, node);
            low[node]=min(low[node], low[newnode]);
        }
    }
    fin[node]=timer++;
}

int main()
{
        #ifdef TKD
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif

    while(sf2(n,m)==2 && n && m) {
        mem(low, -1);
        mem(visit, 0);
        FOR1(i,n) edge[i].clear();

        FOR1(i, m) {
            int u, v, c;
            sf3(u,v,c);
            if(c==1) {
                edge[u].pb(v);
            }
            else {
                edge[u].pb(v);
                edge[v].pb(u);
            }
        }
        timer=0;
        FOR1(i, n) {
            if(visit[i]) continue;
            dfs(i, 0);
        }


        int scc=1;
        FOR1(i, n) {
            if(low[i]!=low[1]) scc=0;
        }

        if(scc) puts("1");
        else puts("0");
    }
    return 0;
}
