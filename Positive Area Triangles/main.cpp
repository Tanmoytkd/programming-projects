#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main() {
	long long x, y;
	cin >> x >> y;

	long long res=0LL;
	for(long long m=1; m<=x; m++) {
		for(long long n=1; n<=y; n++) {
			long long row = m+1 , col = n+1;
			long long p = 2*(row+col) - 4;

			long long multi = (x-m+1)*(y-n+1);
			multi %= mod;

			long long type012345 = max(2*(p-2), 0LL) + max(2*(row-2), 0LL) + max(2*(col-2), 0LL);
			long long type6789 = max(4*(row-2)*(col-2), 0LL);
			type012345 %= mod;
			type6789 %= mod;

			long long num = (type012345+type6789)%mod;

			multi *= num;
			multi %= mod;
			
			res += multi;
			res %= mod;
		}
	}

	cout << res << endl;

	return 0;
}