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
    int n;
    sf1(n);

    if(n>=1 && n<=4) cout << "few" << endl;
    else if(n>=5 && n<=9) puts("several");
    else if(n>=10 && n<=19) puts("pack");
    else if(n>=20 && n<=49) puts("lots");
    else if(n>=50 && n<=99) puts("horde");
    else if(n>=100 && n<=249) puts("throng");
    else if(n>=250 && n<=499) puts("swarm");
    else if(n>=500 && n<=999) puts("zoudns");
    else puts("legion");
    return 0;
}
