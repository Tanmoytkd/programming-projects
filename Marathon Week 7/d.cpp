#include <bits/stdc++.h>
using namespace std;

int n, m;

int dp[1007][1007], arr[1007];

int go(int pos, int mod) {
	//cout << mod << endl;
	if(pos==n) {
		if(mod==0) return 1;
		else return 0;
	}

	if(dp[pos][mod]==-1) {
		int & ret = dp[pos][mod];
		ret = 0;
		ret = go(pos+1, mod);
		int newmod = (mod+ arr[pos])%m;
		ret = ret || go(pos+1, newmod);
	}
	return dp[pos][mod];
}

int main() {
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	if(n>m) {
		cout << "YES" << endl;
		return 0;
	} 
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		arr[i]%=m;
	}
	
	
	int res = go(0, m);
	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}