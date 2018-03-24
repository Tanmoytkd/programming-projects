#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int res = INT_MAX;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(k%x==0) res = min(res, k/x);
    }

    cout << res << endl;
    return 0;
}
