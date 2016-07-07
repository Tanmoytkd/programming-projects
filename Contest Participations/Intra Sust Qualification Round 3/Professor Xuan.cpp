#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int fib[1000];


int rev(int n) {
	int res=0;
	while(n) {
		res=res*10+n%10;
		n/=10;
	}
	return res;
}

int fibo(int num) {
	if(fib[num]!=-1) return fib[num];
	int othernum=abs(num-rev(num));

	fib[num]=othernum+fibo(othernum);
	return fib[num];
}

int main() {
    fib[0]=0;
	for(int i=1; i<1000; i++) {
		fib[i]=-1;
	}
	for(int i=1; i<1000; i++) {
		fibo(i);
	}
	int maxi=0;
	for(int i=2; i<1000; i++) {
		if(fib[i]<maxi) fib[i]=maxi;
		if(fib[i]>maxi) maxi=fib[i];
	}

	int t, n;
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		pf("%d\n", fib[n]);
	}

	return 0;
}
