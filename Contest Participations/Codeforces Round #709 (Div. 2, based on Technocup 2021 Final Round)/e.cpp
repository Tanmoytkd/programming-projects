#include <bits/stdc++.h>
using namespace std;
#define mxn 300007

int parent[mxn], beauty[mxn], height[mxn], pos[mxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        cin >> height[i];

        pos[height[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> beauty[i];
    }

    for (int h = 1; h <= n; h++) {
        int hpos = pos[h];
    }

    return 0;
}