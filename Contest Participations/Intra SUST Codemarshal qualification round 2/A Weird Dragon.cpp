#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back
#define Pb pop_back

using namespace std;

long double area(long long x, long long r) {
	long double a=asin((long double)x/r);
	long double ar=(long double) x/(r*r) * sqrt((long double) r*r-x*x);
	a+=ar;
	return a;
}


int main() {
	long long r, l, w;
	while(cin >> r >> l >> w) {
		if(l<w) {
			long long temp=l;
			l=w;
			w=temp;
		}

		long double ans;

		if(r<=w) {
			ans = acos(-1)*r*r;
			cout << ans << endl;
			continue;
		}
		else if((l*l+w*w)<=4*r*r) {
			ans = l*w;
			cout << ans << endl;
			continue;
		}
		else {
			long double extra=4*r*r;
			long double right=0, up=0;
			if(r>w) {
				up=area(r, r)-area(w, r);
			}
			if(r>l) {
				right=area(r, r)-area(l, r);
			}

			extra*=(up+right);
			ans=acos(-1)*r*r-extra;
			cout << ans << endl;
		}

	}
	return 0;
}
