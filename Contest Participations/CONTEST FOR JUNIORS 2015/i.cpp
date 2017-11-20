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

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};

int curr=0;

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif


    int m, n;
    while(sf2(m, n)==2) {
        int possible=1, x=0, y=0;

        string in;
        int val;
        while(n--) {
            cin >> in >> val;

            if(in=="MOVE") {
                FOR(i, val) {
                    x+=dirx[curr];
                    y+=diry[curr];
                }
                if(x<0 || x>m || y<0 || y>m) possible=0;
            }
            else {
                if(val==0) {
                    curr++;
                    curr%=4;
                }
                else {
                    curr--;
                    curr+=4;
                    curr%=4;
                }
            }
        }

        if(possible) cout << y << " " << x << endl;
        else cout << -1 << endl;
    }
    return 0;
}
