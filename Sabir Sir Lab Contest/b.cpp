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
	int cnt=0, dnt=0;
	for(int i=0; i<n; i++) {
		if(arr[i]<m) cnt++;
		if(arr[i]>m) dnt++;
	}
	cout << cnt << " " << dnt << endl;
	return 0;
}
