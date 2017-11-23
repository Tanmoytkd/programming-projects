#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int tst=1; tst<=t; tst++) {
        int a,b,c;
        cin >> a >> b >> c;
        cout << "Case " << tst << ": ";
        if(c%(__gcd(a,b))==0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
