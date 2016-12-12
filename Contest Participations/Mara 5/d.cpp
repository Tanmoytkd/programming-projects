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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 5000
#define maxN 2505
using namespace std;

int n, d[maxN], maxsize, firstday;
vector<int> adj[maxN];

void ReadInput() {
   int m, v;
   scanf("%d", &n);
   For (i, 0, n-1) {
      scanf("%d", &m);
      while (m--) {
         scanf("%d", &v);
         adj[i].push_back(v);
      }
   }
}

void BFS(int u) {
   For (i, 0, n) d[i] = INF;
   queue<int> Queue;
   Queue.push(u); d[u] = 0;
   while (!Queue.empty()) {
      u = Queue.front(); Queue.pop();
      for (int i=0; i<adj[u].size(); i++) {
         int v = adj[u][i];
         if (d[v]==INF) {
            d[v] = d[u]+1;
            Queue.push(v);
         }
      }
   }
}

main() {
   int m, u;
   ReadInput();
   scanf("%d", &m);
   while (m--) {
      scanf("%d", &u);
      if (adj[u].size()>0) {
         BFS(u);
         maxsize = 0; firstday = -1;
         sort(d, d+n);
         int len = 1;
         For (i, 1, n)
            if (d[i-1]==d[i]) len++;
            else {
               if (d[i-1]!=INF && len>maxsize) {
                  maxsize = len;
                  firstday = d[i-1];
               }
               len = 1;
            }
         if (firstday==0) firstday++;
         printf("%d %d\n", maxsize, firstday);
      }
      else puts("0");
   }
}
