#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int test=1; test<=t; test++) {
		long long a, b, res;
		cin >> a >> b;
		res=a+b;
		pf("Case %d: %lld\n", test, res);
	}
	return 0;	
}