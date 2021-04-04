#include <bits/stdc++.h>
using namespace std;
#define div 100000

long long ceildiv(long long up, long long down) {
    return (up + down - 1) / down;
}

long long operation(long long t, long long ki, long long x) {
    if (t == 1) {
        return ki + ceildiv(x, div);
    } else {
        return ceildiv(ki*x, div);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int level[m+1];
    memset(level, -1, sizeof level);
    level[0] = 0;

    for (int timestamp = 1; timestamp <= n; timestamp++) {
        long long t, x, y;
        cin >> t >> x >> y;

        for (int k = 0; k <= m; k++) {
            if (level[k] == -1) {
                continue;
            }

            if (level[k] > n) {
                level[k] -= n;
                continue;
            }

            long long ki = k;
            for (int a = 1; a <= y; a++) {
                ki = operation(t, ki, x);

                if (ki > m) {
                    break;
                }

                if (level[ki] != -1) {
                    break;
                }

                // cout << ki << " comes from " << k << " using " << x << " " << a << " times" << endl;
                level[ki] = n+timestamp;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << level[i] << " ";
    }
    cout << endl;

    return 0;
}