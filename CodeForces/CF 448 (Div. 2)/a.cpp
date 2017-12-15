#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	int diff=360;
	for(int i=0; i<n; i++) {
		int sum=0;
		for(int j=i; j<n; j++) {
			sum+=arr[j];

			int other = 360-sum;
			diff=min(diff, abs(sum-other));
		}
	}

	cout << diff << endl;
	return 0;
}