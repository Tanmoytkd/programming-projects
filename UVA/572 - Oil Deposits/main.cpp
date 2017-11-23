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
#define fg(x, y) fgets(x, y, stdin)
using namespace std;

char arr[102][102];
int m, n;

void dfs(int i, int j) {
    for(int row=i-1; row<=i+1; row++)
        for(int col=j-1; col<=j+1; col++) {
            if(row<0 || row>=m || col<0 || col>=n) continue;
            if(arr[row][col]=='@') {
                arr[row][col]=arr[i][j]+1;
                dfs(row, col);
            }
        }
}

int main() {
    char blank[1000];
    while(sf2(m, n) && m) {
        fg(blank, 999);

        for(int i=0; i<m; i++) {
            sf("%s", arr[i]);
        }

        int counter=0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]=='@') {
                    arr[i][j]=1;
                    counter++;
                    dfs(i, j);
                }
            }
        }
        pf1(counter);
    }
    return 0;
}
