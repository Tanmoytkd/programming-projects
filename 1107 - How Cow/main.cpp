#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int test;
	cin >> test;
	for(int t=1; t<=test; t++) {
		int x1, x2, y1, y2, n, x, y;
		cin >> x1 >> y1 >> x2 >> y2;
		pf("Case %d:\n", t);
		cin >> n;
		while(n--) {
			cin >> x >> y;
			if(x1<x && x<x2 && y1<y && y<y2) pf("Yes\n");
			else pf("No\n");
		}
	}
	return 0;
}
