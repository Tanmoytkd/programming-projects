#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long dp[31][30*30+1];

long long go(int row, int left) {
    if(left==0) return 1;
    if(row==n) {
        if(left==0) return 1;
        else return 0;
    }

    if(dp[row][left]==-1) {
        long long & ret = dp[row][left];
        ret=0;
        ret+=(n-(k-left))*go(row+1, left-1);
        ret+=go(row+1, left);
        //cout << dp[row][left] << endl;
    }
    return dp[row][left];
}

int main() {
    long long t;
    cin >> t;
    for(long long tst=1; tst<=t; tst++) {
        cin >> n >> k;
        //cout << n << " " << k << endl;
        memset(dp, -1, sizeof dp);
        long long res;
        if(k>n) res=0;
        else res=go(0, k);

        printf("Case %lld: %lld\n", tst, res);
    }
    return 0;
}
