#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

int main() {
    int t, x, s;
    cin >> t >> s >> x;
    int diff=x-t;
    int error=diff%s;
    if(x<t) cout << "NO" << endl;
    else if(!error) cout << "YES" << endl;
    else if(error==1 && diff>s) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
