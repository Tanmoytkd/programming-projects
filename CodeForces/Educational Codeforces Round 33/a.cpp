#include <bits/stdc++.h>
using namespace std;

int getTheOther(int a, int b) {
	int cnt[4];
	memset(cnt, 0, sizeof cnt);

	cnt[a]=cnt[b]=1;
	for(int i=1; i<=3; i++) {
		if(cnt[i]==0) return i;
	}
}

int main() {
	int possible = 1;
	int spec = 3;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int winner;
		cin >> winner;
		//cout << winner << " " << spec << endl;
		if(winner==spec) possible = 0;
		spec = getTheOther(winner, spec);
	}

	if(possible) cout << "YES" << endl;
	else cout << "NO" << endl;


	return 0;
}