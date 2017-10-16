#include <bits/stdc++.h>
using namespace std;

int main() {
	std::vector<long long> v;
	for(long long i=1; ; i++) {
		if(i*(i+1)/2>1e9+7) break;
		v.push_back(i*(i+1)/2);
	}
	long long n;
	cin >> n;

	int found=0;
	for(int i=0; i<v.size(); i++) {
		long long srch=n-v[i];
		if(binary_search(v.begin(), v.end(), srch)) found=1;
	}

	if(found) cout << "YES" << endl;
	else cout << "NO" << endl;
}