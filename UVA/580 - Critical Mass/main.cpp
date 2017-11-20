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

int dp[35][4], n;

int go(int pos, int stk) {
    if(pos==n) {
        if(stk==2) return 1;
        else return 2;
    }
    if(dp[pos][stk]==-1) {
        int l=go(pos+1, 0), r=0;
        if(stk<2) r=go(pos+1, stk+1);
        dp[pos][stk]=l+r;
    }
    return dp[pos][stk];
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    while(sf1(n) && n) {
        memset(dp, -1, sizeof(dp));

        int res=1<<n;

        res-=go(1, 0);

        pf1(res);
    }
    return 0;
}
