#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007LL

long long n, m;
long long dp[11][1001];

long long rec(int pos, int diff) {
    if(diff<0) return 0;
    if(pos==m) return 1;

    long long & ret = dp[pos][diff];
    if(ret==-1) {
        ret = 0;
        for(long long i=0; i<=diff; i++) {
            long long newdiff = diff - i;
            long long possible_combinations = i+1;
            long long mul = possible_combinations * rec(pos+1, newdiff);
            mul %= mod;
            ret += mul;
            ret %= mod;
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << rec(0, n-1) << endl;

    return 0;
}
