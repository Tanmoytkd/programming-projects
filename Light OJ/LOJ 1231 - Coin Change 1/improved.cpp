#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
#define mod 100000007
using namespace std;

long long counter=0, n, k, coin[51], occur[51], dp[100][1001];

long long rec(long long pos, long long left) {
	if(left<0) return 0;
	if(left==0) {
		return 1;
	}
	if(pos==n) return 0;

	if(dp[pos][left]==-1) {
		dp[pos][left]=0;
		long long money=0, maxmoney=coin[pos]*occur[pos];
		for(money=0; money<=maxmoney; money+=coin[pos]) {
			if(left>=money) {
				dp[pos][left]+=rec(pos+1, left-money);
			}
			if(left<money) break;
		}
	}
	return dp[pos][left]%mod;
}

int main() {
	long long test;
	cin >> test;
	for(long long t=1; t<=test; t++) {
		cin >> n >> k;
		for(long long i=0; i<n; i++) {
            for(long long j=0; j<=k; j++) {
                dp[i][j]=-1;
            }
		}

		for(long long i=0; i<n; i++) {
			cin >> coin[i];
		}

		for(long long i=0; i<n; i++) {
			cin >> occur[i];
		}

		counter=rec(0, k);

		pf("Case %lld: %lld\n", t, counter);
	}
	return 0;
}
