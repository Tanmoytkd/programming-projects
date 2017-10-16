#include <bits/stdc++.h>
using namespace std;

double dp[107], arr[107];

int main() {
	int t;
	scanf("%d", &t);

	for(int tst=1; tst<=t; tst++) {
		int n;
		scanf("%d", &n);

		for(int i=0; i<n; i++) {
			scanf("%lf", &arr[i]);
		}

		dp[n-1]=arr[n-1];
		for(int pos=n-2; pos>=0; pos--) {
			int nxtpos=min(pos+6, n-1);
			double div=nxtpos-pos;

			dp[pos]=0;
			for(int i=pos+1; i<=nxtpos; i++) {
				dp[pos]+=arr[pos]+dp[i];
			}
			dp[pos]/=div;
		}

		printf("Case %d: %.14lf\n", tst, dp[0]);
	}
	return 0;
}