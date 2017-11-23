/*input
2
1 3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n+7];
	for(int i=0; i<n; i++) cin >> arr[i];

	int gcd = arr[0];
	for(int i=0; i<n; i++) gcd=__gcd(gcd, arr[i]);

	if(gcd!=1) {
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}

	std::vector<int> v;
	if(arr[0]&1) v.push_back(1);
	for(int i=1; i<n; i++) {
		if(arr[i]&1) {
			if(arr[i-1]&1) v.back()++;
			else v.push_back(1);
		}
	}



	int res=0;
	for(int j=0; j<v.size(); j++) {
		if(v[j]&1) res++;
		res+= (v[j]+1)/2;
	}

	cout << "YES" << endl;
	cout << res << endl;

	return 0;
}