/*input
1

.....51..
81..346..
9....8...
.6.8....2
.........
7....2.1.
...1....8
..368..59
..24.....

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
using namespace std;

int row[9], col[9], box[9];
int n, rows, cols, boxes, b[9][9], found=0, nr, nc;

int parity(int n) {
    int counter=0;
    while(n>0) {
        counter+=n&1;
        n>>=1;
    }
    return counter;
}

int incomplete() {
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(!b[i][j]) return 1;
    return 0;
}

void rec(int r, int c) {
    int ibox=(r/n)*n+c/n;
	if(r==rows) {
		found=1;
		return;
	}
	else if(b[r][c]) {
		nc=c+1;
		nr=r+(nc==cols);
		nc=nc%cols;
		rec(nr, nc);
		return;
	}
    int check= (row[r]|col[c])|box[ibox];


	for(int i=1; i<=rows; i++) {
		if(found) return;

		int exist = (check>>i) & 1;
		if(exist) continue;

		b[r][c]=i;
		row[r]|= (1 << i);
		col[c]|= (1 << i);
		box[ibox]|= (1 << i);


		int conf=0;

        int nrow=0, ncol=0, ran=0;
        for(int ni=0; ni<rows; ni++) {
            for(int nj=0; nj<cols; nj++) {
                if(b[ni][nj]) continue;
                int ibox=(ni/n)*n+nj/n;

                int check=row[ni]|col[nj]|box[ibox];
                check=parity(check);
                if(check==9) conf=1;
                if(check>ran ) {
                    ran=check;
                    nrow=ni;
                    ncol=nj;
                }
            }
        }
        if(!conf) {
            rec(nrow, ncol);
        }

		//////
//		if(!conf) {
//            nc=c+1;
//            nr=r+(nc==cols);
//            nc=nc%cols;
//            rec(nr, nc);
//		}
        /////

        if(found==0) {
            b[r][c]=0;
            row[r]&= ~(1 << i);
            col[c]&= ~(1 << i);
            box[ibox]&= ~(1 << i);
        }
	}
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    char blank[1000];
	n=3;
	int test;
	sf("%d", &test);
	gets(blank);


	for(int t=1; t<=test; t++) {
        pf("Case %d:\n", t);
		int blankrow, blankcol;
		found=0;
		rows=cols=boxes=n*n;
        gets(blank);

		for(int i=0; i<rows; i++) {
			row[i]=0;
			col[i]=0;
			box[i]=0;
		}

		int noconflict=1;

		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
				int ibox=(i/n)*n+j/n;
				char data;
				sf("%c", &data);
				if(data=='.') b[i][j]=0;
				else b[i][j]= data-'0';

				if(b[i][j]) {
					noconflict = noconflict && (row[i]^=(1 << b[i][j]));
					noconflict = noconflict && (col[j]^=(1 << b[i][j]));
                    noconflict = noconflict && (box[ibox]^=(1 << b[i][j]));
				}
			}
			gets(blank);
		}

        int nrow=0, ncol=0, ran=0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(b[i][j]) continue;
                int ibox=(i/n)*n+j/n;

                int check=row[i]|col[j]|box[ibox];
                check=parity(check);
                if(check>ran) {
                    ran=check;
                    nrow=i;
                    ncol=j;
                }
            }
        }


		if(noconflict) rec(nrow, ncol);

		if(!noconflict || found==0) pf("NO SOLUTION\n");
		else {
			for(int i=0; i<rows; i++) {
				for(int j=0; j<cols; j++) {
					pf("%d", b[i][j]);
				}
				puts("");
			}
		}
	}

	return 0;
}
