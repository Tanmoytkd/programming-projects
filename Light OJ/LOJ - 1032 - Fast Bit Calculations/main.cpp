#include <bits/stdc++.h>
using namespace std;

long long dp[2][2][35];
long long val[35];

void generate(long long n) {
	for(long long i=0; i<35; i++) {
		val[i]=n%2;
		n/=2;
	}
	reverse(val, val+35);
}

long long value(long long bit) {
	long long res=0;
	for(long long i=bit; i<35; i++) {
		res*=2;
		res+=val[i];
	}
	return res;
}

long long power(long long base, long long pwr) {
	if(pwr==0) return 1;
	if(pwr%2==1) return base*power(base, pwr-1);
	long long res = power(base, pwr/2);
	return res*res;
}

long long rec(long long small, long long prevOne, long long bit) {
	if(bit==35) return 0;
	long long & ret = dp[small][prevOne][bit];
	if(ret!=-1) return ret;
	ret = 0;

	if(small) {
		ret+=rec(small, 0, bit+1);
		long long add=0;
		if(prevOne) add = power(2, 35-bit-1);
		ret+= add + rec(small, 1, bit+1);
	}
	else {

		ret+= rec(val[bit], 0, bit+1);		
		
		if(val[bit]) {
			long long add=0;
			if(prevOne) {
				add=(value(bit+1)+1);
			}
			//if(bit==3) cout << "add = " << add << endl;
			ret+= add + rec(small, 1, bit+1);
			//if(bit==3) cout << "bit: " << bit << " --- " << small << ' ' << prevOne << ":  " << ret << endl;
		}

	}
	//cout << "bit: " << bit << " --- " << small << ' ' << prevOne << ":  " << ret << endl;
	return ret;
}

int main() {
	long long t;
	scanf("%lld", &t);

	for(long long tst=1; tst<=t; tst++) {
		memset(dp, -1, sizeof dp);
		memset(val, 0, sizeof val);

		long long n;
		scanf("%lld", &n);

		// cout << n << endl;

		generate(n);

		//cout << value(4) << endl;

		// for(long long i=0; i<35; i++) cout << val[i] << ' ';
		// cout << endl;

		long long res = rec(0, 0, 0);

		printf("Case %lld: %lld\n", tst, res);

	}

	return 0;
}