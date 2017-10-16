#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	string arr[n];
	for(int i=n-1; i>=0; i--) {
		cin >> arr[i];
	}

	map<string, int> mark;
	for(int i=0; i<n; i++) {
		string & str=arr[i];
		if(mark[str]==1) continue;
		cout << str << endl;
		mark[str]=1;
	}
	return 0;
}