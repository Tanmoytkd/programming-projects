#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        long long cost[n+1];

        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
        }

        long long res = LLONG_MAX;

        long long oddmin = cost[1];
        long long evenmin = cost[2];
        long long oddsum = 0;
        long long evensum = 0;
        long long oddcnt = 0;
        long long evencnt = 0;

        for (long long seg = 1; seg <= n; seg++) {
            if (seg % 2 == 1) {
                oddmin = min(oddmin, cost[seg]);
                oddsum += cost[seg];
                oddcnt++;
            } else {
                evenmin = min(evenmin, cost[seg]);
                evensum += cost[seg];
                evencnt++;
            }

            if (seg == 1) {
                continue;
            }

            long long h_cost = (oddsum - oddmin) * 1 + (n - (oddcnt - 1)) * oddmin;
            long long v_cost = (evensum - evenmin) * 1 + (n - (evencnt - 1)) * evenmin;

            // cout << h_cost << " " << v_cost << endl;
            long long total_cost = h_cost + v_cost;
            res = min(res, total_cost);
        }

        cout << res << endl;
    }

    return 0;
}