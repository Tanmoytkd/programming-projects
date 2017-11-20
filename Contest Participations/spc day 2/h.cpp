/*input
    2

    4

    1 4 5

    1 2 20

    1 3 10

    2 3 5

    2 4 10

    3 4 20

    4

    1 4 2

    1 4 20

    1 4 20

*/
#include <bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi() printf("hi!\n")
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

using namespace std;
typedef long long int lint;
typedef double dbl;

#define mx 100

int main() {
    int nodes,edges,s,t,st,en,cst,i,j,test,tst=0;
    int r [mx][mx];
    int parent[mx];
    int cost[mx];
    int vis[mx];
    scanf("%d",&test);

    while (test--) {
        scanf("%d %d %d %d",&nodes,&s,&t,&edges);
    	for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
            	r[i][j]=0;
        s--;t--;
        for(i=0;i<edges;i++){
            scanf("%d %d %d",&st,&en,&cst);
            st--;
            en--;
            r[st][en] += cst;
            r[en][st] += cst;
        }
        cost[s] = INT_MAX;
        parent[s] = s;
        int maxflow = 0;
        int path = 1;
        while (path) {
            path = 0;
            queue<int> q;
            for(i=0;i<nodes;i++)vis[i]=0;
            //for(i=0;i<nodes;i++)parent[i]=i;
            q.push(s);

            vis[s] = 1;
            while (!q.empty()) {
                int u =q.front();q.pop();
                if (u == t) {
                    path = 1;
                    break;
                }
                for (int i = 0; i < nodes; i++)
                    if (r[u][i] > 0 && !vis[i]) {
                        parent[i] = u;
                        cost[i] = min(cost[u], r[u][i]);
                        vis[i] = 1;
                        q.push(i);
                    }
            }
            if (path) {
                maxflow += cost[t];
                int u = t;
                while (parent[u] != u) {
                    r[parent[u]][u] -= cost[t];
                    r[u][parent[u]] += cost[t];
                    u = parent[u];
                }
            }
        }
        printf("Case %d: %d\n",++tst,maxflow);
    }
	return 0;
}
