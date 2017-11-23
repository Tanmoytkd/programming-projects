/*input
3
1 5
2 6
3 7
2
2 4
1 4
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
bool fn(pii a, pii b) {
	return a.second < b.second;
}
int main() {
	int n;
	cin >> n;
	std::vector<pii> v1;
	for(int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		v1.push_back(pii(l,r));
	}
	int m;
	cin >> m;
	std::vector<pii> v2;
	for(int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		v2.push_back(pii(l,r));
	}
	sort(v1.begin(), v1.end(), fn);
	sort(v2.begin(), v2.end());
	int res=0;
	int t1=v2.back().first - v1.front().second;
	res=max(res, t1);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), fn);
	int t2=v1.back().first - v2.front().second;
	
	res=max(res, t2);
	
	// cout << t1 << " " << t2 << endl;
	cout << res << endl;
	return 0;
}