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
#define pii pair<int,int>
using namespace std;

struct node {
    int x, y, dist;
    node(int a, int b, int c) {
        x=a;
        y=b;
        dist=c;
    }
};

int r, c, fx[4]={0,0,1,-1}, fy[4]={1,-1,0,0};

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    while(sf2(r,c)==2 && r && c) {
        if(r==0 && c==0) break;
        int row, col, rows;
        sf1(rows);
        int bd[r][c], level[r][c];
        memset(bd, 0, sizeof bd);
        memset(level, 0, sizeof level);

        while(rows--) {
            sf1(row);
            int cols;
            sf1(cols);
            while(cols--) {
                sf1(col);
                bd[row][col]=1;
            }
        }

        int srow, scol, erow, ecol;
        sf2(srow, scol);
        sf2(erow, ecol);

        int timer=-1;

        queue< pii > q;
        q.push( pii(srow, scol));
        level[srow][scol]=1;

        while(!q.empty()) {
            if(timer!=-1) break;
            pii co=q.front();
            row=co.first;
            col=co.second;
            int dist=level[row][col];
            q.pop();

            int nrow, ncol;
            FOR(i,4) {
                nrow=row+fx[i];
                ncol=col+fy[i];

                if(nrow==erow && ncol==ecol) {
                    level[nrow][ncol]=dist+1;
                    timer=dist+1;
                    break;
                }

                if(nrow<0 || nrow>=r || ncol<0 || ncol>=c) continue;
                if(level[nrow][ncol]==0 && bd[nrow][ncol]==0) {
                    q.push( pii(nrow, ncol));
                    level[nrow][ncol]=dist+1;
                }
            }
        }

        pf1(timer-1);
    }
    return 0;
}
