#include<bits/stdc++.h>
using namespace std;
#define mx 100007
#define pii pair<int, int>


vector< pii > edge[mx];
long long arr[mx], n, k;

int dfs(int u, int par)
{
    long long sum = 1;
    vector<pii>& e = edge[u];
    for(int i=0; i<e.size(); i++)
    {
        pii q = e[i];
        int v = q.first;
        int w = q.second;
        if(v==par) continue;
        long long x = dfs(v, u);
        long long y = n - x;
        arr[v] = x*y*w;
        sum += x;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i<n-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    dfs(1, -1);
    sort(arr+1, arr+n+1);

    long long ans = 0;
    for(int i = n-k; i>0; i--) ans += arr[i];
    ans*=2;

    cout << ans << endl;
    return 0;
}
