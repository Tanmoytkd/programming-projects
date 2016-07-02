#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

long long n, dp[22][3], price[22][3], mini=INT_MAX;

long long rec(long long pos, long long prev) {
	if(pos==n) return 0;

	if(dp[pos][prev]==-1) {
		long long icost=INT_MAX;
		for(long long i=0; i<3; i++) {
			if(i==prev) continue;

			long long cost1=price[pos][i]+rec(pos+1, i);
			if(cost1<icost) icost=cost1;
		}
		dp[pos][prev]=icost;
	}

	return dp[pos][prev];
}


int main() {
	long long test, cost;
	sc("%lld", &test);

	for(long long t=1; t<=test; t++) {
		sc("%lld", &n);
		mini=INT_MAX;

		for(long long i=0; i<n ; i++) {
			for(long long j=0; j<3; j++) {
				sc("%lld", &price[i][j]);
				dp[i][j]=-1;
			}
		}

		cost=price[0][0]+rec(1, 0);
		if(cost<mini) mini=cost;

		cost=price[0][1]+rec(1, 1);
		if(cost<mini) mini=cost;

		cost=price[0][2]+rec(1, 2);
		if(cost<mini) mini=cost;

        pf("Case %lld: %lld\n", t, mini);

	}
	return 0;
}
