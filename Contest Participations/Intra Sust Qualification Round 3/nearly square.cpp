#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int test;
	sc("%d", &test);

	for(int t=1; t<=test; t++) {
		long long m, n;
		sc("%lld", &m);
		n=sqrt(m);
		long long n1= n*n, n2=(n+1)*(n+1), diff1=m-n1, diff2=n2-m;
		pf("Case %d: ", t);
		if(diff1<=diff2) pf("%lld %lld\n", n, 0-diff1);
		else pf("%lld %lld\n", n+1, diff2);
	}
	return 0;	
}