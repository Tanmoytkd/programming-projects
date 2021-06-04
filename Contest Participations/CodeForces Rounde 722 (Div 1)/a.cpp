#include <bits/stdc++.h>
using namespace std;

#define low 0
#define high 1

vector<int> edges[100007];
long long val[100007][2];
int parent[100007], value[100007];

long long dp[100007][2];

long long rec(int node, int mode) {
    if (dp[node][mode] != -1) {
        return dp[node][mode];
    }

    value[node] = val[node][mode];
    vector<int>& e = edges[node];

    long long result = 0;

    for (int i = 0; i < e.size(); i++) {
        int child = e[i];
        if (child != parent[node]) {
            parent[child] = node;

            long long lowResult = abs(value[node] - val[child][low]) + rec(child, low);
            long long highResult = abs(value[node] - val[child][high]) + rec(child, high);

            result += max(lowResult, highResult);
        }
    }

    dp[node][mode] = result;
    return dp[node][mode];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            edges[i] = vector<int>();
            cin >> val[i][0] >> val[i][1];
        }

        int u, v;
        for (int i = 0; i < n-1; i++) {
            cin >> u >> v;

            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        memset(dp, -1, sizeof dp);
        cout << max(rec(1, 0), rec(1, 1)) << endl;
    }

    return 0;
}