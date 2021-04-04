#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int indegree[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> indegree[i];
    }

    vector<pair<int, pair<int, int>>> pairs;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }

            if (indegree[i] < indegree[j]) {
                continue;
            }

            int diff = indegree[i] - indegree[j];
            pairs.push_back({-diff, {i, j}});
            // cout << diff << " - " << i << ", " << j << endl;
        }
    }

    sort(pairs.begin(), pairs.end());

    for (auto p: pairs) {
        int i = p.second.first, j = p.second.second;

        cout << "? " << i << " " << j << endl;
        fflush(stdout);

        string s;
        cin >> s;

        if (s == "Yes") {
            cout << "! " << i << " " << j << endl;
            return 0;
        }
    }

    cout << "! " << 0 << " " << 0 << endl;

    return 0;
}