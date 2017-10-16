#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long a, b;
	cin >> a >> b;
	unsigned long long zap = a^b;
	//cout << zap << endl;
	int pos=0;
	while(zap>0) {
		pos++;
		zap/=2;
	}
	unsigned long long res=(1LL<<pos)-1;
	cout << res << endl;
	return 0;
}