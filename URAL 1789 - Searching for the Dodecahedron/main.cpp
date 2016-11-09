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
#define FOR(I, N) for(I=0; I<N; I++)
#define FOR1(I, N) for(I=1; I<=N; I++)

using namespace std;

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif


    int n;
    sf1(n);

    pf1(n<<1);

    for(int i=1; i<=n; i++) pf("%d ", i);
    for(int i=n; i>1; i--) pf("%d ", i);
    pf1(1);
    return 0;
}
