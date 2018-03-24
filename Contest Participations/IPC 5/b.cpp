#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int tst=1; tst<=t; tst++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		printf("Case %d: ", tst);
		if(c%__gcd(a,b)) {
			puts("No");
		}
		else {
			puts("Yes");
		}
	}
	return 0;
}