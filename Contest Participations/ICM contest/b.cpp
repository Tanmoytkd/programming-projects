#include <bits/stdc++.h>
using namespace std;

int dp[1000007][10], mul[1000007];

int f(int n) {
    int res=1;
    while(n) {
        int dig = n%10;
        if(dig!=0) res*=dig;
        n/=10;
    }
    return res;
}

int main() {
    for(int i=1; i<=1000000; i++) {
        if(i<10) mul[i]=i;
        else mul[i]=mul[f(i)];
    }
//    cout << "tkd" << endl;

    for(int i=1; i<=1000000; i++) {
        for(int dig = 1; dig<=9; dig++) {
            dp[i][dig]=dp[i-1][dig];
        }
        dp[i][mul[i]]++;
    }

    int q;
    scanf("%d", &q);

    while(q--) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);

        cout << dp[r][k]-dp[l-1][k] << endl;
    }

    return 0;
}
