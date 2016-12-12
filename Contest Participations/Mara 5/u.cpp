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

int m, n;
int area=0, maxarea=0, dirx[4] = {0, 0, -1, 1}, diry[4]={1, -1, 0, 0};
char bd[25][25], land='l';

void dfs(int row, int col) {
    area++;
    if(area>maxarea) maxarea=area;
    bd[row][col]=0;

    FOR(i, 4) {
        int nrow= row + diry[i];
        int ncol= col + dirx[i];

        if(ncol<0) ncol+=n;
        if(ncol>=n) ncol-=n;

        if(nrow<0 || nrow>=m) continue;
        if(bd[nrow][ncol]==land) dfs(nrow, ncol);
    }
}


int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    while(sf2(m, n)==2) {
        memset(bd, 0, sizeof bd);
        gets(bd[0]);

        FOR(i, m) {
            gets(bd[i]);
        }

        int row, col;
        sf2(row, col);
        land = bd[row][col];
        dfs(row, col);

        area=0;
        maxarea=0;

        FOR(i, m) {
            FOR(j, n) {
                if(bd[i][j]==land) {
                    area=0;
                    dfs(i, j);
                }
            }
        }

        cout << maxarea << endl;

    }



    return 0;
}
