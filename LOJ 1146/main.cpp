#include <bits/stdc++.h>
using namespace std;


struct point {
	long double x, y;
	point(): x(0), y(0) {}
	point(long double a, long double b): x(a), y(b) {}
	point operator+(point b) {
		return point(x+b.x, y+b.y);
	}

	point operator-(point b) {
		return point(x-b.x, y-b.y);
	}

	point operator/(long double div) {
		return point(x/div, y/div);
	}

	point operator*(long double mul) {
		return point(x*mul, y*mul);
	}
};

long double abs(const point & A) {
	return sqrt(A.x*A.x+A.y*A.y);
}

long double dist(point & A, point & B, point & C, point & D, long double tm) {
	point p1=A+(B-A)*tm, p2=C+(D-C)*tm;
	return abs(p2-p1);

}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tst=1; tst<=t; tst++) {
		long double ax,ay, bx, by, cx, cy, dx, dy;
		cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
		//cout << ax << " "<< ay<< " " << bx << " "<< by<< " " << cx<< " " << cy<< " " << dx<< " " << dy<< " "<< endl;
		point A(ax, ay), B(bx, by), C(cx, cy), D(dx, dy);

		long double low=0, high=1;
		while(high-low>(1e-9)) {
			//cout << low << " " << high << endl;
			long double m1=low+(high-low)/3.0;
			long double m2=high-(high-low)/3.0;
			//cout << "m1 " << m1 << " m2 " << m2 << endl;
			long double d1=dist(A, B, C, D, m1), d2=dist(A,B,C,D, m2);
			//cout << d1 << " " << d2 << endl;
			if(fabs(d1-d2)<=(1e-8)) {
				low=m1, high=m2;
			}
			else if(d1<d2) high=m2;
			else low=m1;
		}

		//cout << high << " " << low << endl;
		long double mid = (high+low)/2;
		
		long double res = dist(A,B,C,D,mid);

		cout << fixed << setprecision(14) << "Case " << tst << ": " << res << endl;;
	}
	return 0;
}