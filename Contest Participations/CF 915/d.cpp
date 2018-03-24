#include <bits/stdc++.h>
using namespace std;
int n, m, start, finish, loopfound, visited[505];
vector<int> edge[505], cycle, parents;
int dontdetect = 0;

void dfs(int u)
{
    if(loopfound) return;
    visited[u]++;
    parents.push_back(u);
    vector<int> & e = edge[u];

    for(int i=0; i<e.size(); i++)
    {
        if(loopfound) break;
        int v = e[i];

        if(u==start && v==finish) continue;
        if(visited[v]==2) continue;
        if(visited[v]==0) dfs(v);
        if(visited[v]==1) {
            if(!dontdetect) {
                cycle.push_back(v);
                while(!parents.empty() && parents.back()!=v)
                {
                    int last = parents.back();
                    cycle.push_back(last);
                    if(!parents.empty()) parents.pop_back();
                }
                cycle.push_back(v);
                reverse(cycle.begin(), cycle.end());
            }

            loopfound=1;
            break;
        }
    }

    if(!parents.empty()) parents.pop_back();
    visited[u]++;
}

int main() {
    scanf("%d%d", &n, &m);

    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        edge[u].push_back(v);
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i])dfs(i);
        if(loopfound) break;
    }

    int sz = cycle.size()-1;

    dontdetect=1;
    for(int i=0; i<sz; i++) {
        start = cycle[i];
        finish = cycle[i+1];

        loopfound=0;
        memset(visited, 0, sizeof visited);
        parents.clear();
        //cycle.clear();
        for(int j=1; j<=n; j++) {
            if(visited[j]==0) dfs(j);
            if(loopfound) break;
        }

        if(!loopfound)  {
            cout << "YES" << endl;
            return 0;
        }
    }

    if(loopfound) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
