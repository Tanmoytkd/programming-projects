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
        double x1, fx1, x2, fx2, xt1, fxt2;
		cout << "Case " << t << ": ";
		cin >> x1 >> fx1;
		cin >> x2 >> fx2;

		if(x1==x2 && fx1==fx2) {
			cout << "ambiguous ambiguous" << endl;
			continue;
		}
		else if(x1==x2 && fx1!=fx2) {
			cout << "no solution no solution" << endl;
			continue;
		}

		cin >> xt1 >> fxt2;

		double m= (double) (fx2-fx1)/ (double) (x2-x1);
		double c= (double) (fx1-m*x1);

		double fxt1= m*xt1+c;
		double xt2=(fxt2-c)/m;

		pf("%.9lf %.9lf\n", fxt1, xt2);
//		cout << fixed << setprecision(9) << fxt1 << " " << xt2 << endl;
	}
	return 0;
}
