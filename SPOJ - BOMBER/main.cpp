#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int rec (int row, int col) {
	if(row>col) swap(row, col);
	
	if(row==1) return 1;
	if(row==0) return 0;

	if(dp[row][col]==-1) {
		dp[row][col]=0;
		
		for(int i=1; i<=row; i++) {
			if(dp[row][col]) break;
			for(int j=1; j<=col; j++) {
				int cnt=0;
				cnt+=rec(i-1, j-1);
				cnt+=rec(i-1, col-j);
				cnt+=rec(row-i, j-1);
				cnt+=rec(row-i, col-j);
				if(cnt%2==0) {
					dp[row][col]=1;
					break;
				}
			}
		}
	}
	return dp[row][col];
}

int main() {
	memset(dp, -1, sizeof dp);
	rec(100, 100);
	int t;
	scanf("%d", &t);
	while(t--) {
		int m, n;
		scanf("%d%d", &m,&n);
		if(rec(m, n)) puts("1");
		else puts("2");
	}
}