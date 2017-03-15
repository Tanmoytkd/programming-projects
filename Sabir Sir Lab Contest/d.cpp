#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	int m;
	scanf("%d", &m);
	int mini=m, imax=m;
	for(int i=0; i<n; i++) {
		if(arr[i]<m) mini=min(mini, arr[i]);
		if(arr[i]>m) imax=max(imax, arr[i]);
	}
	cout << mini << " " << imax << endl;
	return 0;
}
