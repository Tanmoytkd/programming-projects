#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;
	int arr[k];
	for(int i=0; i<k; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+k);

	int sum=0;
	for(int i=0; i<=k/2; i++) {
		sum+=(arr[i]+1)/2;
	}
	cout << sum << endl;
}