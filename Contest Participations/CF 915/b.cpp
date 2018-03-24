#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b)
{
    return max(a,b)-min(a,b);
}

int main()
{
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;

    if(l==1 && r==n) cout << 0 << endl;
    else if(l==1) cout << dist(pos, r) + 1 << endl;
    else if(r==n) cout << dist(pos, l) + 1 << endl;
    else
    {
        int res1 = dist(pos, l) +   1 + dist(l, r) + 1;
        int res2 = dist(pos, r) + 1 + dist(l, r) + 1;
        cout << min(res1, res2) << endl;
    }
    return 0;
}
