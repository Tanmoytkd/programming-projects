#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int P[1000], W[1000], dp[1002][32], cap, n;

int rec(int i, int w) {
	if(i>=n) return 0;
	if(dp[i][w]!=-1) return dp[i][w];
	if(w==cap) return 0;
	int p1=rec(i+1, w), p2=0;

	if(w+W[i]<=cap) p2=rec(i+1, w+W[i])+P[i];
	dp[i][w]=max(p1, p2);
	return dp[i][w];
}

int main() {
	int t;
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i=0; i<n; i++) sc("%d %d", &P[i], &W[i]);
		int g, ans=0;
		sc("%d", &g);
		while(g--) {
			sc("%d", &cap);
			memset(dp, -1, sizeof(dp));
			ans+=rec(0, 0);
		}
		pf("%d\n", ans);
	}
	return 0;
}