#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[30][30];
std::vector<int> v;

long long go(int pos, int prev) {
	if(pos>=k) {
		// cout << "chuka ";
		// for(int i=0; i<v.size(); i++) {
		// 	cout << v[i] << " ";
		// }
		// cout << endl;
		return 1;
	}
	if(prev==n-1) return 0;
	if(dp[pos][prev]==-1) {
		long long & ret=dp[pos][prev];
		ret=0;
		for(int i=prev+1; i<n; i++) {
			v.push_back(i);
			ret+=go(pos+1, i);
			v.pop_back();
		}
	}
	return dp[pos][prev];
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		long long res=go(0, 0);
		cout << res << endl;
	}

}