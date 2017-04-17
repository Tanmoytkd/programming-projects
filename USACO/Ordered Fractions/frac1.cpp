/*
ID: tanmoyk2
PROG: frac1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

struct frac {
	int up, down;
	frac(int a, int b) {
		up=a;
		down=b;

		int g=__gcd(up, down);
		if(g!=0) {
			up/=g;
			down/=g;
		}
		if(down<0) {
			up*=-1;
			down*=-1;
		}
	}
	frac() {}

	friend bool operator< (frac a, frac b); 
};

bool operator< (frac a, frac b) {
	return a.up*b.down < a.down*b.up;
}

int main() {
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	set<frac> s;

	int n;
	fin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=i; j++) {
			s.insert(frac(j,i));
		}
	}

	set<frac>::iterator it;
	for(it=s.begin(); it!=s.end(); it++) {
		frac f = *it;
		fout << f.up << "/" << f.down << endl;
	}
}