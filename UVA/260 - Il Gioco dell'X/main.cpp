#include <bits/stdc++.h>

#define pf printf
#define pf1(x) printf("%d\n", x)
#define sf scanf
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)

#define pb push_back
#define Pb pop_back

using namespace std;

int dirx[6]= {-1, -1, 0, 0, 1, 1};
int diry[6]= {-1, 0, -1, 1, 0, 1};

int n;
char blank[1000], board[201][201], checker[201][201];
char winner;

void run(int row, int col) {
    if(row<0 || row>=n || col<0 || col>=n) return;
    if(winner=='w' || checker[row][col]) return;

    checker[row][col]=1;

    if(col==(n-1)) {
        winner='w';
        return;
    }

    for(int i=0; i<6; i++) {
        if(winner=='w') return;
        int newrow=row+dirx[i];
        int newcol=col+diry[i];
        if(newrow<0 || newrow>=n || newcol<0 || newcol>=n) continue;
        if(board[newrow][newcol]=='w') run(newrow, newcol);
    }
}

int main() {
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int counter=1;


    while(sf1(n)==1 && n) {
        gets(blank);

        for(int i=0; i<n; i++) {
            sf("%s", board[i]);
        }

        winner='b';

        for(int row=0; row<n; row++) {
            if(board[row][0]=='w') run(row, 0);
        }


        pf("%d ", counter++);
        if(winner=='b') pf("B\n");
        else pf("W\n");


        for(int i=0; i<n; i++) {
            memset(checker[i], 0, n);
        }
    }

    return 0;
}
