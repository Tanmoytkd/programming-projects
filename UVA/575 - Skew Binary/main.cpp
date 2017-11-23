#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string sk;
    while(cin >> sk) {
        if(sk=="0") break;
        long long res=0, tp=1, pos=sk.length()-1;
        for(; pos>=0; pos--) {
            tp<<=1;
            res+= (sk[pos]-'0')*(tp-1);
        }
        cout << res << endl;
    }

    return 0;
}
