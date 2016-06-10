#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	long long n;
	while(sc("%lld", &n)==1) {
		int sum=0;
		while(n) {
			sum+=n%10;
			n/=10;
		}
		pf("%d\n", sum);
	}

	return 0;
}
