#include <bits/stdc++.h>
using namespace std;
#define MX (250000+7)

long long dp[MX], m;

long long fact(int n) {
    n%=m;
    if(dp[n]==-1) {
        if(n<=1) dp[n]=1%m;
        else dp[n] = (n*fact(n-1))%m;
    }
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof dp);

    long long n;
    cin >> n >> m;

    dp[0]=1;
    for(int i=1; i<MX; i++) {
        dp[i] = (dp[i-1]*i)%m;
    }

    long long res = 0;
    for(int i=1; i<=n; i++) {
        long long s = (n-i+1)%m;

        long long addable = (s*s)%m;
        addable *= fact(i);
        addable %= m;
        addable *= fact(n-i);
        addable %= m;

        res += addable;
        res %= m;
    }

    cout << res << endl;
//    cout << fact(250000) << endl;
    return 0;
}
