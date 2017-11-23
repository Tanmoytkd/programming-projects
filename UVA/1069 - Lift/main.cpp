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
		int you, lift;
		cin >> you >> lift;
		int distance=abs(you-lift)+you;
		int result=distance*4+19;
		pf("Case %d: %d\n", t, result);
	}
	return 0;	
}