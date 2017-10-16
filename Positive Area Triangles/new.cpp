#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

long long comb(long long n) {
	if(n<3) return 0;
	long long a=n, b=n-1, c=n-2;
	if(a%2==0) a/=2;
	else if(b%2==0) b/=2;
	else c/=2;

	if(a%3==0) a/=3;
	else if(b%3==0) b/=3;
	else c/=3;

	long long res= (a*b) % mod;
	res*=c;
	return res%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	long long x, y;
	cin >> x >> y;

	int res=0;
	for(int m=1; m<=x; m++) {
		for(int n=1; n<=y; n++) {
			long long row = m+1 , col = n+1;
			long long p = 2*(row+col) - 4;

			long long multi = (x-m+1)*(y-n+1);
			multi %= mod;

			long long add = comb(p);
			long long rem1 = (2*(((((row-2)*(row-2))%mod)*(col-2))%mod))%mod;
			long long rem2 = (2*(((((col-2)*(col-2))%mod)*(col-2))%mod))%mod;
			long long rem = (rem1+rem2)%mod;

			long long num = (((add - rem)%mod)+mod)%mod;

			multi*=num;
			multi%=mod;
			
			res+=multi;
			res%=mod;
		}
	}

	cout << res << endl;

	return 0;
}