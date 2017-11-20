#include <bits/stdc++.h>

#define pf printf
#define pf1(x) printf("%d\n", x)
#define sf scanf
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)

#define pb push_back
#define Pb pop_back

using namespace std;

int main() {
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int test;
    sf1(test);

    while(test--) {
        int g, l;
        sf2(g,l);

        if(l%g==0) pf("%d %d\n", g, l);
        else pf("-1\n");
    }

    return 0;
}
