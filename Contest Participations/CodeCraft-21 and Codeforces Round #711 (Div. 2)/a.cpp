#include <bits/stdc++.h>
using namespace std;

long long gcdsum(long long n) {
    long long original_n = n;

    long long sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return __gcd(sum, original_n);
}

void solve(long long n) {
    for (long long x = n; ; x++) {
        if (gcdsum(x) > 1) {
            cout << x << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        solve(n);
    }

    return 0;
}