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
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)
#define mx 1048576

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> edge[mx + 7];

int n;
int bfs()
{
    queue<int> Q;
    int dist[n+7];
    mem(dist, -1);
    Q.push(1);
    dist[1] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(edge[u].size()==1 || !edge[u].size()) return dist[u]+1;
        FOR(i, edge[u].size())
        {
            int v = edge[u][i];
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
}
int main()
{
    int t, tst = 1;
    while(sf1(n)!=EOF)
    {
        int l, r;
        FOR(i, n) edge[i+1].clear();
        FOR(i, n) {
            sf2(l, r);
            if(l) edge[i+1].pb(l);
            if(r) edge[i+1].pb(r);
        }
        pf1(bfs());

    }
    return 0;
}
