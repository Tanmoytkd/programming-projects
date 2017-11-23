#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int sum, a;
		cin >> sum;
		a=sum>>1;
		cout << a << " " << sum-a << endl;
	}
	return 0;	
}