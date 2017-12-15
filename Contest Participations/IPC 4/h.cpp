#include <bits/stdc++.h>
using namespace std;
#define N 200007
#define MOD 1000000007LL
long long fact[N];



long long bigmod(long long base, long long power) {
	if(power==0) return 1;
	if(power%2==1) {
		return (base* bigmod(base, power-1))%MOD;
	}
	long long x = bigmod(base, power/2);
	return (x*x)%MOD;
}

long long inverse(long long a) {
	return bigmod(a, MOD-2);
}

long long sieve() {
	fact[0]=1;
	for(long long i=1; i<N; i++) {
		fact[i]=i*fact[i-1];
		fact[i]%=MOD;
	}
}

long long ncr(long long n, long long r) {
	if(r==0) return 1;
	if(n<r) return 0;

	long long up = fact[n];
	long long down = (fact[n-r] * fact[r])%MOD;
	down = inverse(down);
	return (up*down)%MOD;
}

int main() {
	sieve();
	long long n;
	scanf("%lld", &n);

	long long res = ncr(n+n-1, n);
	
	res*=2;
	res-=n;
	res%=MOD;
	res+=MOD;
	res%=MOD;

	printf("%lld\n", res);
}