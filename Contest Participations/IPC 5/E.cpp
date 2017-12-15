#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[55][55], visit[55][55];

int found=0;

int fx[4] = {-1, 1, 0, 0};
int fy[4] = {0, 0, -1, 1};

void dfs(int row, int col, int prow, int pcol) {
	visit[row][col]=1;

	for(int i=0; i<4; i++) {
		int nrow = row+fx[i];
		int ncol = col+fy[i];

		if(nrow==prow && ncol==pcol) continue;
		if(nrow<0 || nrow>=n || ncol<0 || ncol>=m) continue;
		if(board[nrow][ncol]!=board[row][col]) continue;
		if(visit[nrow][ncol]) {
			found=1;
			return;
		}
		dfs(nrow, ncol, row, col);
	}
}


int main() {
	
	scanf("%d%d", &n, &m);

	for(int i=0; i<n; i++) {
		scanf("%s", board[i]);
	}

	for(int i=0; i<n; i++) {
		if(found) break;
		for(int j=0; j<m; j++) {
			if(found) break;
			if(visit[i][j]) continue;

			dfs(i, j, -1, -1);
		}
	}

	if(found) puts("Yes");
	else puts("No");



	return 0;
}