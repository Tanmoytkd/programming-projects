#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits.h>

using namespace std;

int fx[4] = {-1, 1, 0, 0};
int fy[4] = {0, 0, -1, 1};

#define check(num, bit) ( (num>>bit)&1 )

struct board {
	int row;
	int col;
	vector<vector<int> > arr, cnt;
	board(int m, int n) {
		row=m, col=n;
		arr = vector< vector<int> > (m, vector<int>(n));
		cnt = vector< vector<int> > (m, vector<int>(n));
	}

	void takeinput() {
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
	}

	void flip(int i, int j) {
		if(i<0 || i>=row || j<0 || j>=col) return;
		arr[i][j] = !arr[i][j];
		cnt[i][j]++;
		for(int k=0; k<4; k++) {
			int nxtrow = i+fx[k];
			int nxtcol = j+fy[k];
			if(nxtrow<0 || nxtrow>=row || nxtcol<0 || nxtcol>=col) continue;
			arr[nxtrow][nxtcol]= !arr[nxtrow][nxtcol];
		}
	}

	bool flip(int mask) {
		for(int j=0; j<row; j++) {
			if(check(mask, j)) {
				flip(0, j);
				cnt[0][j]++;
			}
		}
		fill();

		return verify();
	}

	bool verify() {
		bool correct = true;
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				if(arr[i][j]!=0) correct=false;
			}
		}
		return correct;
	}

	void fill() {
		for(int i=1; i<row; i++) {
			for(int j=0; j<col; j++) {
				if(arr[i-1][j]) {
					flip(i, j);
				}
			}
		}
	}

	vector<int> & operator[] (int pos) {
		return arr[pos];
	}
};

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	board bd(m, n);
	bd.takeinput();

	int stop = (1<<n);
	for(int mask=0; mask<=stop; mask++) {
		board newbd = bd;
		if(newbd.flip(mask)) {
			for(int i=0; i<m; i++) {
				for(int j=0; j<n; j++) {
					if(j!=0) printf(" ");
					printf("%d", newbd.cnt[i][j]);
				}
				puts("");
			}
			break;
		}
	}

}