#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int counter=1, row, col, board[9];

bool conflict(int r, int c) {
    for(int i=1; i<=8; i++) {
        if(i==c || board[i]==0) continue;
        int diff = abs(i-c)-abs(board[i]-r);
        if(i==c || board[i]==r || diff==0) return true;
    }
    return false;
}

void calculate(int column=1) {

    if(column>8) {
        printf("%2d      ", counter);
        for(int i=1; i<=8; i++) printf("%d%c", board[i], " \n"[i==8]);
        counter++;
        return;
    }

    if(column==col) calculate(column+1);
    else {
        for(int i=1; i<=8; i++) {
            board[column]=i;

            if(!conflict(i, column)) {
                calculate(column+1);
            }

            board[column]=0;
        }
    }
}


int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int TC;
    cin >> TC;

    while(TC--) {
        cin >> row >> col;
        for(int i=1; i<=8; i++) board[i]=0;
        board[col]=row;


        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        counter=1;

        calculate();

        if(TC) cout << endl;
    }

    return 0;
}
