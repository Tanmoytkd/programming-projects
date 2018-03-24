#include <bits/stdc++.h>
using namespace std;

long long nc4(long long n) {
	long long res=1;
	for(long long i=1; i<=4; i++) {
		res*=(n-(i-1));
		res/=i;
	}
	return res;
}

int n;
int arr[10007], mark[10007], cnt[10007];
long long res;
vector<int> primes;

void sieve() {
	for(int i=4; i<=10000; i+=2) mark[i]=1;

	for(int i=3; i*i<=10000; i+=2) {
		if(mark[i]) continue;
		for(int j=i*i; j<=10000; j+=i+i) mark[j]=1;
	}

	mark[0]=mark[1]=1;

	primes.push_back(2);
	for(int i=3; i<=10000; i+=2) if(mark[i]==0) primes.push_back(i);
}

void bct(int pos, long long val, long long items) {
	
	if(val>10000) return;

	
	if(!mark[val]) {
		long long counter=cnt[val];
		
		if(items&1) res-= nc4(counter);
		else res+=nc4(counter);
		mark[val]=1;
	}

	if(pos==primes.size()) {
		return;
	}

	
	
	bct(pos+1, val, items);
	bct(pos+1, val*primes[pos], items+1);

}

void disect(int n) {
	for(int i=1; i*i<=n; i++) {
		if(n%i==0)
		{
			cnt[i]++;
			if(i*i!=n) cnt[n/i]++;
		} 

	}
}

int main() {

	sieve();
	int t;
	scanf("%d", &t);



	for(int tst=1; tst<=t; tst++) {		
		

		memset(mark, 0, sizeof mark);
		memset(cnt, 0, sizeof cnt);

		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &arr[i]);
			disect(arr[i]);
		}

		res= 0;

		bct(0, 1, 0);

		printf("Case %d: %lld\n", tst, res);

	}

	return 0;
}