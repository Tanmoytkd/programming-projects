/*
ID: tanmoyk2
PROG: test
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
    //freopen("output.txt", "w", stdout);
    #endif

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    int a,b;
    sf2(a,b);
    int res=a+b;
    pf1(res);

    return 0;
}
