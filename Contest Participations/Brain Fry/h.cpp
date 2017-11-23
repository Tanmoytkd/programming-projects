#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t); 
	while(t--) {
		int m, n;
		scanf("%d%d", &m, &n);
		char arr[m+1][n+1];
		int dp[m+1][n+1];
		for(int i=0; i<m; i++) scanf("%s", arr[i]);
		// for(int i=0; i<m; i++) puts(arr[i]);
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(i==0 || j==0) dp[i][j]=1;
				else {
					int d1=1, d2=1, d3=1;
					if(arr[i-1][j]==arr[i][j]) d1=dp[i-1][j]+1;
					if(arr[i][j-1]==arr[i][j]) d2=dp[i][j-1]+1;
					if(arr[i-1][j-1]==arr[i][j]) d3=dp[i-1][j-1]+1;
					dp[i][j]=min(d1, d2);
					dp[i][j]=min(dp[i][j], d3);	
				}
			}
		}
		// for(int i=0; i<m; i++) {
		// 	for(int j=0; j<n; j++) {
		// 		printf("%d ", dp[i][j]);
		// 	}
		// 	puts("");
		// }
		int res=1;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				res=max(res, dp[i][j]);
			}
		}

		printf("%d\n", res*res);
	}
}