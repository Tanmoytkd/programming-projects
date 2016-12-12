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
int w, h;
int counter=0;
char bd[25][25];
int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, 1, -1};

void dfs(int row, int col) {
    counter++;
    bd[row][col]++;

    FOR(i, 4) {
        int nrow=row+diry[i];
        int ncol=col+dirx[i];

        if(nrow<0 || nrow>=h || ncol<0 || ncol>=w) continue;
        if(bd[nrow][ncol]=='.') dfs(nrow, ncol);
    }
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int t;
    sf1(t);


    FOR1(test,t) {
        sf2(w, h);
        counter=0;

        memset(bd, 0, sizeof bd);

        FOR(i, h) sf("%s", bd[i]);

        int row, col;
        FOR(i, h) {
            FOR(j, w) {
                if(bd[i][j]=='@') {
                    row=i;
                    col=j;
                }
            }
        }

        dfs(row, col);

        cout << "Case " << test << ": " << counter << endl;
    }
    return 0;
}
