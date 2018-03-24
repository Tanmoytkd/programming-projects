#include <bits/stdc++.h>
using namespace std;

int n, a, b;

long double dp[3007][3007][2];
char mark[3007][3007][2];

long double rec(int pos, int diff, int icpc) {
	if(pos==n) return 0;
	if(mark[pos][diff][icpc]==1) return dp[pos][diff][icpc];

	mark[pos][diff][icpc]=1;

	int aused = (pos+diff)/2;
	int bused = pos-aused;

	long double aleft = a-aused;
	long double bleft = b-bused;

	long double div = (long double) 2*aleft + (long double) bleft;
	long double add = 2;

	if(!icpc) add=1;

	long double & ret = dp[pos][diff][icpc];

	ret = add/(div+add);
	ret += div/(div+add) * (((2*aleft)/(div+add)) * rec(pos+1, diff+1, icpc) + (bleft/(div+add)) * rec(pos+1, diff-1, icpc));

	return ret;
}

int main() {
	// freopen("bonus.in", "r", stdin);
	// freopen("bonus.out", "w", stdout);
	scanf("%d", &n);

	scanf("%d %d", &a, &b);

	cout << fixed << setprecision(12) << rec(0, 0, 1) << endl;
	cout << fixed << setprecision(12) << rec(0, 0, 0) << endl;
	return 0;
}