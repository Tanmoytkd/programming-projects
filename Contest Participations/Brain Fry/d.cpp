#include <bits/stdc++.h>
using namespace std;
#define pi  3.141593

int main() {
	ios_base::sync_with_stdio(false);
	int t;

	long double arr[50];
	arr[1]=1;
	arr[2]=1;
	for(int i=3; i<=40; i++) {
		arr[i]=arr[i-1]+arr[i-2];
	}
	long double mul = 1.00- pi/4.00;
	for(int i=1; i<=40; i++) {
		arr[i]*=arr[i]*mul;
	}
	for(int i=2; i<=40; i++) {
		arr[i]+=arr[i-1];
	}

	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << fixed << setprecision(2) << arr[n] << endl;
	}
}