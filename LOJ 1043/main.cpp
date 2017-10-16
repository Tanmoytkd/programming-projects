#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tst=1; tst<=t; tst++) {
		long double ab, ac, bc, ratio;
		cin >> ab >> ac >> bc >> ratio;
		long double s = (ab+bc+ac)/2.0;
		long double totalarea= sqrt(s*(s-ab)*(s-bc)*(s-ac));

		long double low=0, high=ab, mid;
		while((high-low)>1e-9) {
			mid=(low+high)/2;
			long double k = mid/ab;

			long double kab=k*ab, kac=k*ac, kbc=k*bc, ks=(kab+kbc+kac)/2;



			long double area = sqrt(ks*(ks-kab)*(ks-kbc)*(ks-kac));
			long double rat = area/(totalarea-area);
			if(rat>=ratio) {
				high=mid;
			}
			else {
				low=mid;
			}
		}

		cout << "Case " << tst << ": " << fixed << setprecision(6) <<  (high+low)/2.00 << endl; 

	}
	return 0;
}