#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long double a;
		cin >> a;
		long double bot = 1.00 - (1.00/sqrt(2.00));
		long double res=a/bot;
		cout << fixed << setprecision(1) << res << endl;
	}
	return 0;
}