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

    int t;
    sf1(t);

    while(t--) {
        int a, b, n, m,i;
        sf3(a,b,n);
        sf1(m);

        int mod=1;
        FOR(i, m) {
            mod*=10;
        }

        m=mod;

        a%=m;
        b%=m;

        vector<int> fib;

        fib.pb(a);
        fib.pb(b);
        for(int i=2;1;i++)
        {
            int num=fib[i-1]+fib[i-2];
            num%=m;

            if(num==fib[1] && fib[i-1]==fib[0]) {
                fib.pop_back();
                break;
            }
            else {
                fib.pb(num);
            }
        }

        int len=fib.size();
        n%=len;

        pf1(fib[n]);
    }

    return 0;
}
