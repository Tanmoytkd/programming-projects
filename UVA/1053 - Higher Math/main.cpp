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
		long long a, b, c;
		cin >> a >> b >> c;
		if(a>c) swap(a, c);
		if(b>c) swap(b, c);
		
		pf("Case %d: ", t);
		if(a*a+b*b==c*c) pf("yes\n");
		else pf("no\n");
	}
	return 0;	
}