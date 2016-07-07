#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

char city[100000][18];
long long cost[100000], n, m;

long long binary_searchi(long long money, long long spos, long long epos) {
	long long midpos=(spos+epos)/2;
	long long val=cost[midpos];
	if(val<=money && money<cost[midpos+1]) return midpos;
	else if(val<money) return binary_searchi(money, midpos+1, epos);
	else return binary_searchi(money, spos, midpos);
}

int main() {
	long long test;
	sc("%lld", &test);
	for(long long t=1; t<=test; t++) {
		sc("%lld %lld", &n, &m);
		scanf("%s %lld", city[0], &cost[0]);
		for(long long i=1; i<n; i++) {
			scanf("%s %lld", city[i], &cost[i]);
			cost[i]<<=1;
			cost[i]+=cost[i-1];
		}

		pf("Case %lld:\n", t);

		for(long long i=0; i<m; i++) {
			long long money;
			sc("%lld", &money);
			if(money>=cost[n-1]) pf("Congratulation!\n");
			else {
				long long pos=binary_searchi(money, 0, n-1);
				pf("Sorry! You have to return from city ");
				pf("%s\n", city[pos]);
			}
		}
	}
	return 0;
}
