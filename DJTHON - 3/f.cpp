#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n, bx, x, m, by, y;
    cin >> n >> bx;
    long long xpow=1;
    x = 0;
    vector<int> xdig;
    for(int i=0; i<n; i++) {
        long long int dig;
        cin >>dig;
        x*=bx;
        x+=dig;
    }


    y=0;
    cin >> m >> by;
    vector<int> ydig;
    for(int i=0; i<m; i++) {
        long long int dig;
        cin >> dig;
        y*=by;
        y+=dig;
    }

    if(x<y) cout << "<" << endl;
    if(x>y) cout << ">" << endl;
    if(x==y) cout << "=" << endl;
    return 0;
}
