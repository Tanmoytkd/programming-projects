#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string res="";
    for(int i=0;i<n; i++) {
        if((i/2)&1) res+="a";
        else res+="b";
    }
    cout << res << endl;

    return 0;
}
