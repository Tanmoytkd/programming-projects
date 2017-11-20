#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	long long res=0;
	while(m--) {
		long long a, b, c;
		cin >> a >> b >> c;
		res+=c+c;
	}
	cout << res << endl;
	return 0;
}