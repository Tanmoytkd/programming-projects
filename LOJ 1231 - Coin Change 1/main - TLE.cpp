#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int counter=0, n, k, coin[51], occur[51], dp[100][1001];

void rec(int pos, int left) {
	if(left<0) return;
	if(left==0) {
		counter++;
		return;
	}
	if(pos==n) return;


	int money=0, maxmoney=coin[pos]*occur[pos];
	for(money=0; money<=maxmoney; money+=coin[pos]) {
		if(left>=money) rec(pos+1, left-money);
		if(left<money) break;
	}
}

int main() {
	int test;
	cin >> test;
	for(int t=1; t<=test; t++) {
		cin >> n >> k;
		for(int i=0; i<k; i++)
			for(int j=0; j<n; j++) {
				dp[j][i]=-1;
			}

		for(int i=0; i<n; i++) {
			cin >> coin[i];
		}

		for(int i=0; i<n; i++) {
			cin >> occur[i];
		}

		counter=0;
		rec(0, k);
		pf("Case %d: %d\n", t, counter);
	}
	return 0;
}
