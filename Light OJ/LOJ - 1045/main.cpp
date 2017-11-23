#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
#define MXN 1000001
using namespace std;

double sieve [MXN];

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif


    sieve[0]=sieve[1]=0;
    for(int i=2; i<MXN; i++) sieve[i]=sieve[i-1]+log(i);


	int t;
	cin >> t;
	for(int test=1; test<=t; test++) {
		int n, base;
		cin >> n >> base;
		double result=sieve[n];
		result/=log(base);

		long long finalresult= floor(result)+1;

		pf("Case %d: %lld\n", test, finalresult);
	}
	return 0;
}
