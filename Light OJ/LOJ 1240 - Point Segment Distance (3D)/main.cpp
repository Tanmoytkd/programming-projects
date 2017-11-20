#include<bits/stdc++.h>
using namespace std;

struct point {
	double x, y, z;
	point() {}
	point(double x, double y, double z): x(x), y(y), z(z) {}

	point operator+(point b) {
		return point(x+b.x, y+b.y, z+b.z);
	}
	point operator-(point b) {
		return point(x-b.x, y-b.y, z-b.z);
	}
	point operator*(double mul) {
		return point(mul*x, mul*y, mul*z);
	}	
	point operator/ (double div) {
		return point(x/div, y/div, z/div);
	}

	double abs() {
		return sqrt(x*x+y*y+z*z);
	}
};

double dist(point a, point b) {
	return (b-a).abs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int tst=1; tst<=t;tst++) {
		double x1, y1, z1, x2, y2, z2, x, y, z;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x >> y >> z;

		point A(x1, y1, z1), B(x2, y2, z2), P(x,y,z);

		point low=A, high=B;
		double precision=1e-8;
		while(dist(high,low)>precision) {
			point m1=low+(high-low)/3;
			point m2=high-(high-low)/3;

			if(dist(m1, P)<dist(m2, P)) high=m2;
			else low=m1;
		}

		point mid = (high+low)/2;

		double idist = dist(mid, P);

		cout << fixed << setprecision(14) << "Case " << tst << ": " << idist << endl;
	}
}