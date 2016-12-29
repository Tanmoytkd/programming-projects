#include<bits/stdc++.h>
#define pii pair<lint,lint>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf printf
#define pf1(a) printf("%lld\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %lld: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(lint i=0;i<(x); i++)
#define FOR1(i, x) for(lint i = 1; i<=x ; i++)

using namespace std;
typedef long long lint;
typedef double dbl;

//vector<lint> edge[105], icost[105], res, current;
//lint startpos;
//lint n, m, possible, mindist=INT_MAX, inext;
//lint position[105], timer[105], color[105], parent[105], visit[105][105];
//
//void dfs(lint node, lint prev, lint prnt) {
////    cout << node << endl;
//    position[node]=current.size();
//    current.pb(node);
//    timer[node]=prev;
//    color[node]++;
//
//    vector<lint> & e = edge[node];
//    vector<lint> & cost = icost[node];
//
//    FOR(i, e.size()) {
//        lint next=e[i];
//        if(next==prnt) continue;
//        if(color[next]==1) {
//            possible=1;
//
//            if(prev+cost[i]-timer[next] < mindist) {
//                startpos=position[next];
//                res=current;
//                mindist=prev+cost[i]-timer[next];
//                inext=next;
//            }
//            continue;
//        }
//        if(visit[node][next]) continue;
//        //if(color[next]==2) continue;
//
//        //parent[next]=node;
//        visit[node][next]=1;
//        dfs(next, prev+cost[i], node);
//    }
//
//    color[node]++;
//    current.ppb();
//}

int main()
{
    lint n, m;
    while(sf1(n)==1) {
        if(n==-1) break;

        sf1(m);
        lint graph[n+1][n+1], dist[n+1][n+1];
        FOR1(i, n) {
            FOR1(j, n) {
                graph[i][j]=INT_MAX;
                dist[i][j]=INT_MAX;
            }
        }

        lint temp=m;
        while(m--) {
            lint a, b, c;
            sf3(a,b,c);
            graph[a][b]=dist[a][b]=graph[b][a]=dist[b][a]=min(graph[a][b], c);
        }

        lint prev[105][105];

        FOR1(i, n) {
            FOR1(j, n) {
                prev[i][j]=i;
            }
        }


        lint mindist=INT_MAX;

        vector<int> res;

        FOR1(k, n) {
            for(int i=1; i<k; i++) {
                for(int j=i+1; j<k; j++) {
                    lint d = dist[i][j]+ graph[i][k]+ graph[k][j];
                    if(d<mindist) {
                        mindist=d;
                        res.clear();

                        res.pb(i);
                        lint p=j;
                        while(p!=i) {
                            res.pb(p);
                            p=prev[i][p];
                        }
                        res.pb(k);
                    }

                    if(graph[i][j]>graph[i][k]+graph[k][j]) {
                        graph[i][j]=graph[i][k]+graph[k][j];
                        prev[i][j]=prev[k][j];
                    }
                }
            }
        }


        FOR1(k, n) {
            FOR1(i, n) {
                FOR1(j, n) {
                    if(i==j || j==k || k==i) continue;

                }
            }
        }

        if(mindist==INT_MAX) puts("No solution.");
        else {
            printf("%d", res[0]);
            for(int i=1; i<res.size(); i++) {
                pf(" %d", res[i]);
            }
            puts("");
        }
    }
    return 0;
}

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <string>
//#include <stack>
//#include <queue>
//#include <vector>
//#define inf 0x3f3f3f3f
//#define met(a,b) memset(a,b,sizeof a)
//typedef long long ll;
//using namespace std;
//const int N = 1e2+10;
//const int M = 24005;
//const int INF=0x7ffffff;
//int  dist[N][N], w[N][N];
//int  pre[N][N];
//int  path[N];
//int  n, m, num, minc;
//
//void floyd() {
//    minc=INF;
//    for(int k=1; k<=n; k++) {
//        for(int i=1; i<k; i++)
//            for(int j=i+1; j<k; j++) {
//                int  ans=dist[i][j]+w[i][k]+w[k][j];
//                if(ans<minc) { //ж‰ѕе€°жњЂдји§Ј
//                    minc=ans;
//                    num=0;
//                    int p=j;
//                    while(p!=i) { //йЂ†еђ‘еЇ»ж‰ѕе‰Ќй©±йЃЌеЋ†зљ„и·Їеѕ„е№¶е°†е…¶е­е‚Ёиµ·жќҐ
//                        path[num++]=p;
//                        p=pre[i][p];
//                    }
//                    path[num++]=i;
//                    path[num++]=k;
//                }
//            }
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++) {
//                if(dist[i][j]>dist[i][k]+dist[k][j]) {
//                    dist[i][j]=dist[i][k]+dist[k][j];
//                    pre[i][j]=pre[k][j];
//                }
//            }
//    }
//}
//
//int main() {
//    int  u, v, cost;
//    while(cin >> n) {
//        if(n<0) break;
//        cin >> m;
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++) {
//                dist[i][j]=w[i][j]=INF;
//                pre[i][j]=i;
//            }
//        for(int i=1; i<=m; i++) {
//            scanf("%d%d%d",&u,&v,&cost);
//            if(dist[u][v]>cost)   //е¤„зђ†й‡Ќиѕ№
//                w[u][v]=w[v][u]=dist[u][v]=dist[v][u]=cost;
//        }
//        floyd();
//        if(minc==INF)
//            printf("No solution.\n");
//        else {
//            printf("%d",path[0]);
//            for(int i=1; i<num; i++)
//                printf(" %d",path[i]);
//            puts("");
//        }
//    }
//    return 0;
//}
