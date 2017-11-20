/*input
3
aa
aa
ab
*/
#include <bits/stdc++.h>
using namespace std;

	int pos[100];

int dist(int a, int b, int len) {
	if(b<=a) return a-b;
	else return (len-(b-a));
}

int main() {
	int n;
	cin >> n;
	string s[100];

	for(int i=0; i<n; i++) cin >> s[i];

	int minmove=INT_MAX;

	for(int x=0; x<n; x++) {
		string test = s[x]+s[x];
		int len = test.length();

		for(int i=0; i<n; i++) {
			pos[i] = test.find(s[i]);
			if(pos[i]==string::npos) {
				cout << -1 << endl;
				return 0;
			}
		}

		

		for(int i=0; i<len; i++) {
			int cnt=0;
			for(int j=0; j<n; j++) cnt+=dist(i, pos[j], s[0].size());
			minmove=min(minmove, cnt);
		}

	}

	cout << minmove << endl;

	return 0;
}