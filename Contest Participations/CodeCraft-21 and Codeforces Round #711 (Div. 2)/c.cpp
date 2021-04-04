#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007LL

int dp[1002][1002][2];

int n, k;

int rec(int pos, int k, int right) {
    // cout << pos << " " << k << " " << right << endl;

    if (pos < 0 || pos == n || k == 1) {
        return 1;
    }

    if (dp[pos][k][right] != -1) {
        return dp[pos][k][right];
    }

    int & ret = dp[pos][k][right];

    if (right) {
        ret = (rec(pos+1, k, true) + rec(pos-1, k-1, false)) % mod;
    } else {
        ret = (rec(pos-1, k, false) + rec(pos+1, k-1, true)) % mod;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        memset(dp, -1, sizeof dp);

        cin >> n >> k;

        cout << rec(0, k, true) << endl;
    }

    return 0;
}