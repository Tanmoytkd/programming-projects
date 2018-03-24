#include <bits/stdc++.h>
using namespace std;

int uranium[507][507], radium[507][507], dp[507][507];

int rec(int row, int col) {
	if(row<0 || col<0) return 0;
	if(dp[row][col]==-1) {
		dp[row][col] = max(radium[row][col]+rec(row, col-1), uranium[row][col]+rec(row-1, col));
	}
	return dp[row][col];
}

int main() {
	int t;
	scanf("%d", &t);

	for(int tst=1; tst<=t; tst++) {
		memset(dp, -1, sizeof dp);
		int m, n;
		scanf(" %d %d", &m, &n);

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d", &uranium[i][j]);
				if(j!=0) uranium[i][j]+=uranium[i][j-1];
			}
		}

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d", &radium[i][j]);
				if(i!=0) radium[i][j]+=radium[i-1][j];
			}
		}

		int res = rec(m-1, n-1);
		printf("Case %d: %d\n", tst, res);
	}
	return 0;
}