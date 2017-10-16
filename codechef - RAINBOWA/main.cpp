#include <bits/stdc++.h>
using namespace std;

int palindrome(std::vector<int> v) {
	int i=0, j=v.size()-1;
	while(i<j) {
		if(v[i]!=v[j]) return 0;
		i++;
		j--;
	}
	return 1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++) cin >> arr[i];
		vector<int> v;
		int zero=0;
		int sum=0;
		int pos=0;
		for(int i=1; i<=7; i++) {
			int cnt=0;
			while(pos<n && arr[pos]==i) {
				cnt++;
				pos++;
			}
			if(cnt==0) zero++;
			sum+=cnt;
			v.push_back(cnt);
		}

		for(int i=6; i>=1; i--) {
			int cnt=0;
			while(pos<n && arr[pos]==i) {
				cnt++;
				pos++;
			}
			if(cnt==0) zero++;
			sum+=cnt;
			v.push_back(cnt);
		}
		

		if(zero || (sum!=n)) {
			cout << "no" << endl;
		}
		else if(!palindrome(v)) {
			cout << "no" << endl;
		}
		else {
			cout << "yes" << endl;
		}
	}
	return 0;
}