#include <bits/stdc++.h>
using namespace std;

int cnt[1000007];

int main() {
	int m;
	scanf("%d", &m);
	int arr[m];
	for(int i=0; i<m; i++) {
		scanf("%d", &arr[i]);
		cnt[ arr[i] ] = 1;
	}

	int possible = 1;
	int gcd = arr[0];
	for(int i=0; i<m; i++) {
		gcd = __gcd(gcd, arr[i]);
	}

	if(gcd!=arr[0]) possible=0;

	if(!possible) cout << -1 << endl;
	else {
		printf("%d\n", 2*m-1);
		printf("%d", arr[0]);
		for(int k=1; k<m; k++) {
			printf(" %d", arr[0]);
			printf(" %d", arr[k]);
		} 
		puts("");
	}
	return 0;
}