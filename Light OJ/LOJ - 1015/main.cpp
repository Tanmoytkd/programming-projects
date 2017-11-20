#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int t;
	sc("%d", &t);
	for(int test=1; test<=t; test++) {
		int n, num;
		long long result=0;
		sc("%d", &n);
		while(n--) {
			sc("%d", &num);
			if(num>=0) result+=num;
		}
		pf("Case %d: %lld\n", test, result);
	}
	return 0;
}
