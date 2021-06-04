#include <bits/stdc++.h>
using namespace std;
#define mod 998244353LL



// long long divisors(long long n) {
//     long long div = 2;

//     long long divisors = 0;
//     for (long long i = 1; i*i <= n; i++) {
//         if (n % i == 0) {
//             divisors += 2;

//             if (i*i == n) {
//                 divisors -= 1;
//             }
//         }
//     }

//     // map<long long, long long> cnt;

//     // while (div * div <= n) {
//     //     if (n % div == 0) {
//     //         cnt[div] += 1;
//     //         n /= div;
//     //     }

//     //     div += 1;
//     // }

//     // if (n != 1) {
//     //     cnt[n] += 1;
//     // }

//     // long long divisors = 1;
//     // for (auto it = cnt.begin(); it != cnt.end(); it++) {
//     //     divisors *= (it->second + 1);
//     // }

//     return divisors;
// }

int divisors[1000007];

int main() {
    long long n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j] += 1;
        }
    }

    long long dp[n+1];
    memset(dp, 0, sizeof dp);

    dp[1] = 1;

    for (long long i = 2; i <= n; i++) {
        dp[i-1] += dp[i-2];
        dp[i-1] %= mod;

        dp[i] = (divisors[i] + dp[i-1]) % mod;
    }

    cout << dp[n] << endl;

    return 0;
}