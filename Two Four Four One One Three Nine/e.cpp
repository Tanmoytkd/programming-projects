#include <bits/stdc++.h>
using namespace std;

template <class T>
struct dijkstra {
    long long n;
    vector<vector<pair<long long, T> > > adj;
    vector<T> dist;
    vector<long long> parent, mark;

    dijkstra(long long n): n(n+1), adj(n+1){} //dist and parent will be initialized during calculation

    void addEdge(long long a, long long b, T w) {
        //adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    void findShortestPath(long long src) {
        priority_queue<pair<T,long long>, vector<pair<T, long long> >, greater<pair<T, long long> > > q;
        dist = vector<T>(n, numeric_limits<T>::max());
        parent = vector<long long>(n, -1);
        mark = std::vector<long long> (n, 0);
        dist[src]=0;
        q.push({0, src});

        while(!q.empty()) {
            long long u  = q.top().second;
            mark[u]=1;
            q.pop();
            //T d = q.top().first;

            for(auto edge: adj[u]) {
                long long v= edge.first;
                T d = edge.second;

                if(mark[v]) continue;

                if(dist[v]-d > dist[u]) {
                    dist[v]=d+dist[u];
                    parent[v]=u;
                    q.push({dist[v], v});
                }
            }
        }
    }

    T shortest_distance(long long node) {
        return dist[node];
    }

    vector<long long> shortest_path(long long node) {
        vector<long long> res;
        while(node!=-1) {
            res.push_back(node);
            node=parent[node];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    long long n, s, t;
    cin >> n >> s >> t;
    dijkstra<long long> d(n);
    long long m;
    cin >> m;
    while(m--) {
        long long a, b, cost;
        cin >> a >> b >> cost;
        d.addEdge(a,b,cost);
    }

    long long cnt=0;
    d.findShortestPath(s);
    vector<long long> & dist=d.dist;
    for(long long i=1; i<=n; i++) {

        if(dist[i]<=t) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
