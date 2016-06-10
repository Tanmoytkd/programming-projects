#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

long long dp[300];

long long calc(int n) {
	if(n==0) return 1;
	else if(n==1) return 2;
	else if (n==2) return 3;

	if(dp[n]==-1) dp[n]=calc(n-1)+2*calc(n-2)+3*calc(n-3);
	return dp[n];
}

int main() {
	int n;
	for(int i=0; i<300; i++) dp[i]=-1;
	while(sc("%d", &n)==1) {
		long long res=calc(n);
		pf("%lld\n", res);	
	}

	return 0;
}
