#include <bits/stdc++.h>
using namespace std;
#define mx 300007
#define mod 1000000007
long long cnt[mx], dp[mx], sum[mx], arr[mx];

int main() {

    long long n;
    scanf("%I64d", &n);

    for(long long i=0; i<n; i++) {
        scanf("%I64d", &arr[i]);
    }
    sort(arr, arr+n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << endl;
    }
    cnt[0]=1;
    for(long long i=1; i<n; i++) {
        long long diff = (arr[i]-arr[i-1])%mod;
        dp[i]=(((dp[i-1]+sum[i-1])%mod) +(cnt[i-1]*diff)%mod)%mod;
        sum[i]=(dp[i]+(cnt[i-1]*diff)%mod)%mod;
        cnt[i]=(((cnt[i-1]+cnt[i-1])%mod)+1)%mod;
        //cout << i << ' ' <<  dp[i] << " " << sum[i] << endl;
        //cout << __builtin_popcount(cnt[i]+1) << endl;
    }

    printf("%I64d\n", dp[n-1]);
    return 0;
}
