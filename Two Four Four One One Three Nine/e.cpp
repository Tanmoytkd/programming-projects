#include <bits/stdc++.h>
using namespace std;

template <class T>
struct dijkstra {
    int n;
    vector<vector<pair<int, T> > > adj;
    vector<T> dist;
    vector<int> parent;

    dijkstra(int n): n(n+1), adj(n+1){} //dist and parent will be initialized during calculation

    void addEdge(int a, int b, T w) {
        adj[a].push_back({b, w});
        //adj[b].push_back({a, w});
    }

    void findShortestPath(int src) {
        priority_queue<pair<T,int>, vector<pair<T, int> >, greater<pair<T, int> > > q;
        dist = vector<T>(n, numeric_limits<T>::max());
        parent = vector<int>(n, -1);
        dist[src]=0;
        q.push({0, src});

        while(!q.empty()) {
            int u  = q.top().second;
            q.pop();
            //T d = q.top().first;

            for(auto edge: adj[u]) {
                int v= edge.first;
                T d = edge.second;

                if(dist[v]-d > dist[u]) {
                    dist[v]=d+dist[u];
                    parent[v]=u;
                    q.push({dist[v], v});
                }
            }
        }
    }

    T shortest_distance(int node) {
        return dist[node];
    }

    vector<int> shortest_path(int node) {
        vector<int> res;
        while(node!=-1) {
            res.push_back(node);
            node=parent[node];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    dijkstra<int> d(n);
    int m;
    cin >> m;
    while(m--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        d.addEdge(a,b,cost);
    }

    int cnt=0;
    d.findShortestPath(s);
    vector<int> & dist=d.dist;
    for(int i=1; i<=n; i++) {

        if(dist[i]<t) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
