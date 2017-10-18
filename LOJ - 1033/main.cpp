#include <bits/stdc++.h>
using namespace std;

char str[105];
int dp[105][105];

int rec(int start, int fin) {
	if(start==fin) return 0;
	if(start>fin) return 0;

	if(dp[start][fin]==-1) {
		int & ret = dp[start][fin];
		ret = INT_MAX;

		if(str[start]==str[fin]) ret = rec(start+1, fin-1);
		else ret = 1+ min(rec(start+1, fin), rec(start, fin-1));
	}
	return dp[start][fin];
}

int main() {
	int t, tst=1;
	scanf("%d", &t);
	while(t--) {
		memset(dp, -1, sizeof dp);
		scanf("%s", str);

		printf("Case %d: %d\n", tst++, rec(0, strlen(str)-1));
	}
	return 0;
}