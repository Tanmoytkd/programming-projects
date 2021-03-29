#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    set<int> diff;
    for (int i = 1; i < n; i++)
    {
        diff.insert(arr[i] - arr[i - 1]);

        if (diff.size() > 2)
        {
            cout << -1 << endl;
            return;
        }
    }

    if (diff.size() == 1) {
        cout << 0 << endl;
        return;
    }

    vector<int> d(diff.begin(), diff.end());

    if ((d[0] > 0 && d[1] > 0) || (d[0] < 0 && d[1] < 0) || (d[0] == 0 || d[1] == 0)) {
        cout << -1 << endl;
    } else {
        int s = arr[0];
        int m = d[1] - d[0];
        int c = d[1];

        long long val = s % m;

        for (int i = 0; i < n; i++) {
            if (val != arr[i]) {
                cout << -1 << endl;
                return;
            }

            val += c;
            val %= m;
        }
        cout << m << " " << c << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int test = 1; test <= t; test++)
    {
        solve();
    }

    return 0;
}