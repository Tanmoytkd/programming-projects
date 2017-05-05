#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int newsize = distance(v.begin(), unique(v.begin(), v.end()));
    v.resize(newsize);

    int mx = k*v[v.size()-1];
    char mark[mx+7];
    int level[mx+7];
    memset(mark, 0, sizeof mark);
    fill(level, level+mx+7, 10000);

    queue<int> q;
    level[0]=0;
    q.push(0);
}
