#include <bits/stdc++.h>
using namespace std;

int dp[101][101], arr[101];

int rec(int start, int fin) {
	int res=INT_MIN;
	if(start>fin) return 0;
	if(dp[start][fin]==-1) {
		int sum=0;
		for(int i=start; i<=fin; i++) {
			sum+=arr[i];
			res = max(res, sum-rec(i+1, fin));
		}
		sum=0;
		for(int i=fin; i>=start; i--) {
			sum+=arr[i];
			res = max(res, sum-rec(start, i-1));
		}
		dp[start][fin]=res;
	}
	return dp[start][fin];

}

int main() {
	int t, tst=1;
	scanf("%d", &t);
	while(t--) {
		memset(dp, -1, sizeof dp);

		int n;
		scanf("%d", &n);


		for(int i=0; i<n; i++) {
			scanf("%d", &arr[i]);
		}

		printf("Case %d: %d\n", tst++, rec(0, n-1));
	}

	return 0;
}