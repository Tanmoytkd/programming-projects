#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

long long dp[300];

long long calc(long long b, long long p, long long m) {
	if(p==0) return 1;
	if(dp[p]==-1) {
		if(p&1) dp[p]= ((b%m)*calc(b, p-1, m))%m;
		else {
			long long num = calc(b, p>>1, m);
			dp[p] = (num*num)%m;
		}
	}
	return dp[p];
}

int main() {
	long long b, p, m;
	while(sc("%lld %lld %lld", &b, &p, &m)==3) { 
		for(int i=0; i<300; i++) dp[i]=-1;
		long long res= calc(b, p, m);
		pf("%lld\n", res);	
	}
	return 0;
}
