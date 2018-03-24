#include <bits/stdc++.h>
using namespace std;

int main() {
	long double a=1, b=2, c=1, d=2;
	cin >> a >> b >> c >> d;
	
	long double add = a/b;
	long double res=add;
	long double multi = ((b-a)/b) * ((d-c)/d);

	cout << fixed << setprecision(12) << ((1.00/(1-multi))*(a/b)) << endl;

	//cout << res << endl;
	// for(int i=0; i<1000; i++) {
	// 	add*=multi;
		
	// 	res+=add;
	// //	cout << fixed << setprecision(10) << add << " -- " << res << endl;
	// }

	// cout << fixed << setprecision(12) << res << endl;
}