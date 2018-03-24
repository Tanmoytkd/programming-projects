#include <bits/stdc++.h>
using namespace std;

long long dp[107][107][2];

int n, k;

long long rec(int pos, int left, int one) {
	if(left<0) return 0;
	if(pos==n) {
		if(left==0) return 1;
		else return 0;
	}

	long long & ret = dp[pos][left][one];
	if(ret==-1) {
		ret=0;
		ret+=rec(pos+1, left, 0);
		if(one) ret+=rec(pos+1, left-1, 1);
		else ret+=rec(pos+1, left, 1);
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int tst=1; tst<=t; tst++) {
		scanf("%d", &tst);

		
		scanf("%d%d", &n, &k);

		memset(dp, -1, sizeof dp);

		long long res = rec(0, k, 0);
		printf("%d %lld\n", tst, res);
	}
	return 0;
}