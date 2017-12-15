#include <bits/stdc++.h>
using namespace std;

int main() {
	long double x = 7;
	for(int i=0; i<100; i++) {
		x+=1;
		x=1/x;
	}

	cout << x << endl;
	return 0;
}