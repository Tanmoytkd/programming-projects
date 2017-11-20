/*input
8 1
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	if(n<=m) {
		cout << n << endl;
		return 0;
	}
	long long rest = n-m;

	rest*=2;
	long long res=sqrt(rest);

	while(res*(res+1)<rest) res++;

	cout << res+m << endl;

	return 0;
}