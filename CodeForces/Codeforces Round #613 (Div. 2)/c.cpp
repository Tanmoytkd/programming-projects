#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    long long res = 1;
    for(long long tmp = 2; tmp*tmp<x; tmp++) {
        if(x%tmp==0 && __gcd(tmp, x/tmp)==1) res = tmp;
    }
    cout << res << " " << x/res << endl;

    return 0;
}
