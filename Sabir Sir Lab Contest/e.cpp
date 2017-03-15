
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
	int fst, lst;
	for(int i=0; i<n; i++) {
		if(arr[i]==m) {
			fst=i+1;
			break;
			
		}
	}
	for(int i=n-1; i>=0; i--) {
		if(arr[i]==m) {
			lst=i+1;
			break;
		}
	}
	cout << fst << " " << lst << endl;
	return 0;
}
