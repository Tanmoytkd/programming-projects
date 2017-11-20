#include <bits/stdc++.h>
using namespace std;
#define mx 40


int main() {
    long long dp[mx][mx] = {0};
    for(int i=0; i<40; i++) {
        dp[i][0]=1;
        for(int j=1; j<=i; j++) {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }

    int n, r;
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> r;
        cout << dp[n][r-1] << " " << dp[n-1][r-1] << endl;
    }
    return 0;
}
