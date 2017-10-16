/*input
3
72
30
50
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long double arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];

	sort(arr, arr+n);
	reverse(arr, arr+n);

	long double res = arr[0];
	for(int i=1; i<n; i++) {
		res = 2*sqrt(res*arr[i]);
	}
	cout << fixed << setprecision(3) << showpoint <<  res << endl;

	return 0;
}