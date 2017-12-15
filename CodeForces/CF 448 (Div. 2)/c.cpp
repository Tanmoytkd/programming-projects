#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
int mark[77];
void sieve() {
	for(int i=4; i<=70; i+=2) mark[i]=1;

	for(int i=3; i*i<=70; i+=2) {
		if(mark[i]) continue;
		for(int j=i*i; j<=70; j+=i+i) mark[j]=1;
	}

	mark[0]=mark[1]=1;

	primes.push_back(2);
	for(int i=3; i<=70; i+=2) if(mark[i]==0) primes.push_back(i);
}

int cnt[77], mask[77];

#define set(num, bit) num|=(1<<bit)

int generatemask(int n) {
	int mask=0;
	for(int i=0; i<primes.size(); i++) {
		int p = primes[i];
		int cnt=0;
		while(n%p==0) {
			cnt++;
			n/=p;
		}
		if(cnt%2==1) set(mask, i);
	}
	return mask;
}

#define mod 1000000007

long long bigmod(long long base, long long p) {
	if(p==0) return 1;
	if(p%2==1) return (base*bigmod(base, p-1))%mod;
	long long x = bigmod(base, p/2);
	return (x*x)%mod;
}

int dp[71][1<<19];

long long rec(int num, int msk) {
	if(num>=71) return (msk==0);
	if(cnt[num]==0) return rec(num+1, msk);

	long long ret = dp[num][msk];
	if(ret==-1) {
		
		ret = (bigmod(2, cnt[num]-1) * (long long) rec(num+1, msk))%mod;
		int newmask = msk^mask[num];

		ret += (bigmod(2, cnt[num]-1) * (long long) rec(num+1, newmask))%mod;
		ret %=mod;

		dp[num][msk]=ret;
	}
	return ret;
}

int main() {
	sieve();

	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
	}



	for(int i=1; i<=70; i++) {
		mask[i]=generatemask(i);
	}

	memset(dp, -1, sizeof dp);
	long long res = rec(1, 0);

	cout << res-1 << endl;
}