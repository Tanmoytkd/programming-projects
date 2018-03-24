#include <bits/stdc++.h>
using namespace std;
#define mod 342307123
struct pr {
	int zero, one;
	pr() {
		zero=0;
		one=0;
	}

	pr(int a, int b) {
		zero=a%mod;
		one=b%mod;
	}

	pr operator+(pr b) {
		return pr(zero+b.zero, one+b.one);
	}

	bool operator==(pr b) {
		return zero==b.zero && one==b.one;
	}

};

pr dp[2][2][10007];

pr rec(int x, int y, int stepleft) {
	if(!stepleft) return pr();

	pr & ret = dp[x][y][stepleft];
	if(ret==pr()) {
		if(x==y) ret=pr(1, 0) + rec(x, 0, stepleft-1) + rec(0, y, stepleft-1);
		if(x!=y) ret=pr(0, 1) + rec(x, 1, stepleft-1) + rec(1, y, stepleft-1);
	}
	return ret;

}

int main() {
	pr x = pr(1, 1) + rec(0, 1, 3);
	cout << x.zero << " " << x.one << endl;

	return 0;
}