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

long long fib[55];

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif
    fib[1]=1;
    fib[2]=2;
    for(int i=3; i<=55; i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int n;
    while(sf1(n)==1 && n) {
        cout << fib[n] << endl;
    }

    return 0;
}
