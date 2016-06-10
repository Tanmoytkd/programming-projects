#include <bits/stdc++.h> 
#define pf printf
#define sc scanf

using namespace std;

long long dp[30];

long long fibo(long long n) {
	if(n==0) return 0;
	else if (n==1) return 1;
	
	if(dp[n]==-1) dp[n]=fibo(n-1)+fibo(n-2);
	return dp[n];
}

int main() {
	long long n;
	while(sc("%lld", &n)) {
	for(int i=0; i<30; i++) dp[i]=-1;
	long long res=fibo(n);
	pf("%lld\n", res);
	}
	return 0;
}
