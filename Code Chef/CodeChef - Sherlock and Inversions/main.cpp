#include <bits/stdc++.h>
using namespace std;

struct data {
	int val;
	int pos;
}

bool comp(data a, data b) {
	return a.val<b.val;
}

int main() {
	int n;
	cin >> n;

	long long arr[n+7];
	data a[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		a[i].val=arr[i];
		a[i].pos=i;
	}
	sort(a, a+n, comp);

	
	return 0;
}