#include <bits/stdc++.h>
using namespace std;
#define lint long long
struct fraction {
	lint up, down;
	fraction(): up(0), down(1) {}
	fraction(lint a, lint b=1): up(a), down(b) {
		lint g=__gcd(up, down);
		if(g) {
			up/=g;
			down/=g;
		}
		
		if(down<0) {
			up=0-up;
			down=0-down;
		}
	}

	operator double () {
		long double ret = up/down;
		long double u= up%down, d=down;
		ret+= u/d;
		return ret;
	}

	fraction operator+(fraction f) {
		lint a=up, b=down, c=f.up, d=f.down, g=__gcd(b,d);
		lint dwn=b;
		if(g) {
			dwn/=g;
		}
		dwn*=d;

		lint upn;
		if(g) upn=(dwn/b)*a + (dwn/d)*c;
		else upn = a*d+b*c;

		return fraction(upn, dwn);
	}

	fraction operator-(fraction f) {
		lint a=up, b=down, c=f.up, d=f.down, g=__gcd(b,d);
		lint dwn=b;
		if(g) {
			dwn/=g;
		}
		dwn*=d;

		lint upn;
		if(g) upn=(dwn/b)*a - (dwn/d)*c;
		else upn = a*d-b*c;

		return fraction(upn, dwn);
	}


	fraction operator*(fraction f) {
		lint a=up, b=down, c=f.up, d=f.down;

		lint g1=__gcd(a,d);
		if(g1) {
			a/=g1;
			d/=g1;
		}
		
		lint g2=__gcd(b,c);
		if(g2) {
			b/=g2;
			c/=g2;
		}

		return fraction(a*c, b*d);
	}

	fraction operator/(fraction f) {
		return (*this)*fraction(f.down, f.up);
	}
};

int main() {
	
}