#include <bits/stdc++.h>
using namespace std;

template <class T>
struct dijkstra {
    int n;
    vector<vector<pair<int, T> > > adj;
    vector<T> dist;
    vector<int> par;

    dijkstra(int n): n(n), adj(n){} //dist and par will be initialized during calculation

    void addEdge(int a, int b, T w) {
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    void findShortestPath(int src) {
        priority_queue<pair<T,int>, vector<pair<T, int> >, greater<pair<T, int> > > q;
        dist = vector<T>(n, numeric_limits<T>::max());
        par = vector<int>(n, -1);
        dist[src]=0;
        q.push({0, src});

        while(!q.empty()) {
            int u  = q.top().second;
            T dist = q.top().first;

            for(auto q: adj[u]) {
                int v= q.first;
                T d = q.second;

                if(dist[v]-d> dist[u]) {
                    dist[v]=d+dist[u];
                    par[v]=u;
                    q.push({dist[v], v});
                }
            }
        }
    }
};

int main() {

    return 0;
}
