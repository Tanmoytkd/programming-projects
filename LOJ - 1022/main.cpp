#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	double pi=2*acos(0.0);
	int t;
	cin >> t;
	for(int test=1; test<=t; test++) {
		double num, result=4-pi;
		cin >>num;
		result*=num*num;
		pf("Case %d: %.2lf\n", test, result);
	}
	return 0;
}
