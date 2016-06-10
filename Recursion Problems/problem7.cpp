#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int calc(int n) {
	if(n==0) return 0;
	int num;
	sc("%d", &num);
	return (num==13) + calc(n-1);
}


int main() {
	int n;
	while(sc("%d", &n)==1) {
		int occur=calc(n);
		pf("%d\n", occur);
	}

	return 0;
}
