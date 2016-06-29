#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int test;
	cin >> test;
	for(int t=1; t<=test; t++) {
		double R, n;
		cin >> R >> n;
		double var= sin(acos(-1)/n);
		double res= R*var/(var+1);

        pf("Case %d: %.10lf\n", t, res);
	}
	return 0;
}
