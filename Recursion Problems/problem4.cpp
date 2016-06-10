#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	long long n;
	while(sc("%lld", &n)==1) {
		int occur=0, dig;

		while(n) {
			dig=n%10;
			if(dig==7) occur++;
			n/=10;
		}
		pf("%d\n", occur);
	}

	return 0;
}
