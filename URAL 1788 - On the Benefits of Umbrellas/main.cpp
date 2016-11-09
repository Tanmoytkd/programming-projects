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
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

bool func(int a, int b) {
    return a>b;
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int n, m;
    sf2(n,m);

    int g[n], b[m];

    FOR(i, n) sf1(g[i]);
    FOR(i, m) sf1(b[i]);

    sort(b, b+m, func);
    sort(g, g+n, func);

    int upset=0, minupset=0;

    int sumg=0, sumboy=0;

    FOR(i, n) sumg+=g[i];
    FOR(i, m) sumboy+=b[i];

    upset=sumg;

    minupset=upset;

    int lim=min(n,m);

    FOR(i, lim) {
        sumboy-=b[i];
        sumg-= g[i];
        upset=sumg+sumboy*(i+1);
        if(upset<minupset) minupset=upset;
    }

    pf1(minupset);

    return 0;
}
