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

char board[27][27];
int row, col;

int res=0;

int dfs(int r, int c) {
    int isize=1;
    for(int i=r-1; i<=r+1; i++)
        for(int j=c-1; j<=c+1; j++) {
            if(i<0 || i>=row || j<0 || j>=col) continue;
            if(board[i][j]=='1') {
                board[i][j]=board[r][c]+1;
                isize+=dfs(i, j);
            }
        }
    return isize;
}

int main() {
    char blank[1000];
    int test;
    sf1(test);
    gets(blank);
    gets(blank);

    for(int t=0; t<test; t++) {
        if(t!=0) pf("\n");

        res=0;

        row=0;
        while(1) {
            gets(board[row]);
            if(strlen(board[row]) == 0) break;
            row++;
        }

        if(row == 0) {
            pf("0\n");
            continue;
        }

        col = strlen(board[0]);

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(board[i][j]=='1') {
                    board[i][j]=1;
                    int current = dfs(i, j);
                    if(current>res) res = current;
                }

        pf1(res);
    }
    return 0;
}
