#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

int row, col;
string action, name;
char board [252][252], color;
int dirx[4]= {-1, 1, 0, 0}, diry[4]={0, 0, -1, 1};

void paste(int x, int y, char prevcolor) {
    if(x==0 || x>col || y==0 || y>row) return;
    if(board[y][x]!=prevcolor) return;

    board[y][x]=color;
    for(int i=0; i<4; i++) paste(x+dirx[i], y+diry[i], prevcolor);
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int final=0, x, y, x1, y1, x2, y2;
    while(1) {
        cin >> action;
        switch(action[0]) {
            case 'X': final=1;
                      break;
            case 'I': cin >> col >> row;
                      for(int i=1; i<=row; i++)
                        for(int j=1; j<=col; j++)
                            board[i][j]='O';
                      break;
            case 'C': for(int i=1; i<=row; i++)
                        for(int j=1; j<=col; j++)
                            board[i][j]='O';
                      break;
            case 'S': cin >> name;
                      cout << name << endl;
                      for(int i=1; i<=row; i++) {
                        for(int j=1; j<=col; j++)
                            cout << board[i][j];
                        cout << endl;
                      }
                      break;
            case 'L': cin >> x >> y >> color;
                      board[y][x]=color;
                      break;
            case 'V': cin >> x >> y1 >> y2 >> color;
                      if(y1>y2) swap(y1, y2);
                      for(int y=y1; y<=y2; y++) board[y][x]=color;
                      break;
            case 'H': cin >> x1 >> x2 >> y >> color;
                      if(x1>x2) swap(x1, x2);
                      for(int x=x1; x<=x2; x++) board[y][x]=color;
                      break;
            case 'K': cin >> x1 >> y1 >> x2 >> y2 >> color;
                      for(int x=x1; x<=x2; x++)
                        for(int y=y1; y<=y2; y++)
                            board[y][x]=color;
                      break;
            case 'F': cin >> x >> y >> color;
                      if(board[x][y]==color) continue;
                      paste(x, y, board[y][x]);
                      break;
            default:  getline(cin, action);
                      //continue;
        }
        if(final) break;
    }

    return 0;
}
