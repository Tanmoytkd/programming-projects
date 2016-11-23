/*
ID: tanmoyk2
PROG:
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

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif
    int l1, l2;
    sf2(l1, l2);

    if(l1%2==0 || l2%2==1) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
