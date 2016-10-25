/*
ID: tanmoyk2
PROG: beads
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

struct bead {
    char color;
    int counter;
    bead(char c, int x) {
        color = c;
        counter=x;
    }
};

int main() {

    //freopen("beads.in", "r", stdin);
    //freopen("beads.out", "w", stdout);

    int n;
    sf1(n);

    string s;
    cin >> s;

    vector<bead> vec;

    vec.pb(bead(s[0], 1));
    for(int i=1; i<n; i++) {
        if(s[i]==s[i-1]) vec.back().counter++;
        else vec.pb(bead(s[i], 1));
    }








    return 0;
}
