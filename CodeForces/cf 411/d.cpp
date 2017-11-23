#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long int mod=1e9+7;
//    cout << mod << endl; //delete it

    long long res=0, obstacle=0;
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i]=='b') {
            obstacle++;
            obstacle%=mod;
        }
        else {
            res+=obstacle;
            res%=mod;

            obstacle+=obstacle;
            obstacle%=mod;
        }
    }
    cout << res%mod << endl;
    return 0;
}
