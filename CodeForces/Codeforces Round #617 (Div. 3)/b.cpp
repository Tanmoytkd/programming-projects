#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        long long n, sum=0;
        cin >> n;

        while(n>=10) {
            sum += (n/10)*10;
            n = (n%10) + (n/10);
        }

        sum += n;
        cout << sum << endl;

    }
    return 0;
}
