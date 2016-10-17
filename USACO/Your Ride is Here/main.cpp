/*
ID: tanmoyk2
PROG: ride
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

int val(const string & s) {
    int res=1;
    for(int i=0; i<s.length(); i++) {
        res*=s[i]-'A'+1;
        res%=47;
    }
    return res;
}

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    #ifdef TKD
    freopen("i.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s1, s2;
    cin >> s1 >> s2;

    int v1=val(s1), v2=val(s2);
    if(v1==v2) cout << "GO" << endl;
    else cout << "STAY" << endl;

    return 0;
}
