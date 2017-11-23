/*input
5 3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m;
	cin >> n >> m;

	long long maxteam = n-(m-1);
	long long resmx = maxteam*(maxteam-1)/2;

	long long minteam = n/m;
	long long mxteam = (n/m)+1, mnteam = (n/m);
	long long r1 = ((n%m) * mxteam*(mxteam-1)/2) + ((m-(n%m)) * mnteam * (mnteam-1)/2);

	long long res = r1;
	cout << res << " " << resmx << endl;
	return 0;
}