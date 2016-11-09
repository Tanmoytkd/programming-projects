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

    int minmove=50, ipos;

    vector<int> pos;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(i<2 && j<2) ipos=0;
            else if(i<2 && j>=2) ipos=1;
            else if(i>=2 && j<2) ipos=-1;
            else ipos=2;
            int num;
            sf("%d", &num);
            if(num==1) pos.pb(ipos);
        }
    }

    for(int i=-1; i<=2; i++) {
        int counter=0;
        for(int j=0; j<4; j++) {
            int diff=abs(pos[j]-i);
            if(diff==3) diff=1;
            counter+=diff;
        }
        if(counter<minmove) minmove=counter;
    }

    pf1(minmove);
    return 0;
}
