#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;

	long long res = 1;

	for(long long k=1; ; k++) {
		long long beauty = ((1LL<<k) - 1)*(1LL<<(k-1));
		//cout << beauty << endl;
		if(beauty>n) break;
		if(n%beauty==0) res = beauty;
	}

	cout << res << endl;
	return 0;
}