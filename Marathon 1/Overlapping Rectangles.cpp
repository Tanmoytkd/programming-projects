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
#define sf4(w,x,y,z) scanf("%d %d %d %d", &w, &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int test;
    sf1(test);

    while(test--) {
        int x1, y1, x2, y2, xx1, yy1, xx2, yy2;
        sf4(x1, y1, x2, y2);
        sf4(xx1, yy1, xx2, yy2);
        int X1=max(x1, xx1);
        int X2=min(x2, xx2);
        int Y1=max(y1, yy1);
        int Y2=min(y2, yy2);

        if(X1<X2 && Y1<Y2) {
            pf("%d %d %d %d\n", X1, Y1, X2, Y2);
        }
        else {
            pf("No Overlap\n");
        }
        if(test) puts("");
    }

    return 0;
}
