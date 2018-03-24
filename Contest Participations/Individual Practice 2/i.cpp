#include <cstdio>
#include <algorithm>
#include<string.h>

using namespace std;

int a[1007], b[1007];

int dp[1007][1007];

int rec(int apos, int bpos) {
	if(bpos<0) return 0;
	int & ret = dp[apos][bpos];
	if(ret==-1) {
		ret=0;
		if(a[apos]>b[bpos]) ret=200 + rec(apos-1, bpos-1);
		if(a[apos]<b[bpos]) ret=-200+ rec(apos, bpos-1);
		if(a[apos]==b[bpos]) {
			ret = max(rec(apos-1, bpos-1), rec(apos, bpos-1)-200);
		}
	}
	return dp[apos][bpos];
}


int main() {
	int n;
	while(scanf("%d", &n)==1 && n) {
		memset(dp, -1, sizeof dp);
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		for(int i=0; i<n; i++) scanf("%d", &b[i]);

		sort(a, a+n);
		sort(b, b+n);

		printf("%d\n", rec(n-1, n-1));
	}
	return 0;
}