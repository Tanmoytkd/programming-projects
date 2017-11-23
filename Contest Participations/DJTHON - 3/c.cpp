/*input
1 10
*/
#include <bits/stdc++.h>

using namespace std;

bool fn(int a, int b) {
	return a>b;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	long long sum=0;
	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		sum+=num;
	}
	long long res=0;
	sort(arr.begin(), arr.end(), fn);
	while(!arr.empty()) {
		if(arr.size()==1) {
			res+=arr.back();
			break;
		}
		res+=sum;
		res+=arr.back();
		sum-=arr.back();
		arr.pop_back();

	}

	cout << res << endl;


	return 0;
}