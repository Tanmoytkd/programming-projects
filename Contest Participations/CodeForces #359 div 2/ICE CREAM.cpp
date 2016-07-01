#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	long long n, x;
	cin >> n >> x;
	char c;
	long long amount, distress=0;
	while(n--) {
		cin >> c;
		while(!(c=='+' || c=='-')) cin >> c;
		cin >> amount;
		if(c=='+') x+=amount;
		else if(c=='-') {
			if(amount>x) distress++;
			else x-=amount;
		}
	}
	cout << x << " " << distress << endl;
	return 0;
}
