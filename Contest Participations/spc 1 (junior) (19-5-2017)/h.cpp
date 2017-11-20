#include <bits/stdc++.h>
using namespace std;

struct dijkstra {
    long long n;
    vector<vector<pair<long long, long long> > > adj, adj2;
    vector<long long> dist, dist2;

    dijkstra(long long n): n(n+1), adj(n+1), adj2(n+1){} //dist and parent will be initialized during calculation

    void addEdge(long long a, long long b, long long w) {
        adj[a].push_back({b, w});
        adj2[b].push_back({a, w});
    }

    void findShortestPath(long long src) {
        priority_queue<pair<long long,long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
        dist = vector<long long>(n, INT_MAX);
        dist[src]=0;
        q.push({0, src});

        while(!q.empty()) {
            long long u  = q.top().second;
            q.pop();
            //long long d = q.top().first;

            for(auto edge: adj[u]) {
                long long v= edge.first;
                long long d = edge.second;

                if(dist[v]-d > dist[u]) {
                    dist[v]=d+dist[u];
                    q.push({dist[v], v});
                }
            }
        }
    }

    void findShortestPath2(long long src) {
        priority_queue<pair<long long,long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
        dist2 = vector<long long>(n, INT_MAX);
        dist2[src]=0;
        q.push({0, src});

        while(!q.empty()) {
            long long u  = q.top().second;
            q.pop();
            //long long d = q.top().first;

            for(auto edge: adj2[u]) {
                long long v= edge.first;
                long long d = edge.second;

                if(dist2[v]-d > dist2[u]) {
                    dist2[v]=d+dist2[u];
                    q.push({dist2[v], v});
                }
            }
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
        while(t--) {
        long long n, m, k, s, t;
        scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &s, &t);
        long long a, b, w;
        dijkstra d(n+1);
        while(m--) {
            scanf("%lld%lld%lld", &a, &b, &w);
            d.addEdge(a,b,w);
        }
        d.findShortestPath(s);
        d.findShortestPath2(t);
        long long res=d.dist[t];
        //cout << res << endl;
        while(k--) {
            scanf("%lld%lld%lld", &a, &b, &w);
            long long adist = d.dist[a], bdist = d.dist2[b];
            if(adist==INT_MAX || bdist==INT_MAX) continue;
            res=min(res, adist+bdist+w);
            adist = d.dist[b];
            bdist = d.dist2[a];
            res=min(res, adist+bdist+w);
        }

        if(res>=INT_MAX) puts("-1");
        else printf("%lld\n", res);
    }

    return 0;
}
