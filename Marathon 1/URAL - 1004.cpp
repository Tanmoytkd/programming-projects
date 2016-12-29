#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
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

using namespace std;
typedef long long int lint;
typedef double dbl;

vector<int> edge[105], icost[105], res, current;
int startpos;
int n, m, possible, mindist=INT_MAX, inext;
int position[105], timer[105], color[105], parent[105], visit[105][105];

void dfs(int node, int prev, int prnt) {
//    cout << node << endl;
    position[node]=current.size();
    current.pb(node);
    timer[node]=prev;
    color[node]++;

    vector<int> & e = edge[node];
    vector<int> & cost = icost[node];

    FOR(i, e.size()) {
        int next=e[i];
        if(next==prnt) continue;
        if(color[next]==1) {
            possible=1;

            if(prev+cost[i]-timer[next] < mindist) {
                startpos=position[next];
                res=current;
                mindist=prev+cost[i]-timer[next];
                inext=next;
            }
            continue;
        }
        if(visit[node][next]) continue;
        //if(color[next]==2) continue;

        //parent[next]=node;
        visit[node][next]=1;
        dfs(next, prev+cost[i], node);
    }

    color[node]++;
    current.ppb();
}

int main()
{
    vector<int> blank;
    while(sf1(n)==1) {
        if(n==-1) break;

        sf1(m);
        int graph[n+1][n+1];
        FOR1(i, n) {
            FOR1(j, n) {
                graph[i][j]=INT_MAX;
            }
        }

        mem(visit, 0);
        memset(color, 0, sizeof color);
        mem(position, 0);
        mem(parent, 0);
        mem(timer, 0);
        possible=0;
        mindist=INT_MAX;
        res=blank;
        current=blank;
        FOR(i, 105) {
            edge[i]=blank;
            icost[i]=blank;
        }


        int temp=m;
        while(m--) {
            int a, b, c;
            sf3(a,b,c);
            graph[a][b]=min(graph[a][b], c);
            graph[b][a]=min(graph[b][a], c);
        }

        FOR1(i, n) {
            FOR1(j, n) {
                if(graph[i][j]==INT_MAX) continue;
                edge[i].pb(j);
                icost[i].pb(graph[i][j]);
                edge[j].pb(i);
                icost[j].pb(graph[i][j]);
            }
        }

        FOR1(i, n) {
            mem(visit, 0);
            memset(color, 0, sizeof color);
            mem(position, 0);
            mem(parent, 0);
            mem(timer, 0);
            dfs(i, 0, 0);
        }

        if(possible) {
            int i;
            for(i=startpos; i<res.size()-1; i++) {
                pf("%d ", res[i]);
            }
            pf("%d\n", res[i]);
//            cout << inext << endl;
        }
        else {
            puts("No solution.");
        }
    }
    return 0;
}
