#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;


bool distinct(int n1, int n2) {
	int a=n1/1000;
	int b=n1%1000;
	int c=n2/1000;
	int d=n2%1000;
	if(a==b || b==c || c==d || d==a) return false;
	return true;
}

int main() {
	int n;
	while(sc("%d", &n)==1) {
		if(n==0) break;
		bool found=false;
		long long res;
	
		long long arr[n];
		for(int i=0; i<n; i++) sc("%lld", &arr[i]);
		sort(arr, arr+n);

		map<long long, int> add;
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				long long pos=arr[i]+arr[j];
				add[pos]=i*1000+j;
			}
		}

		for(int i=n-1; i>=1; i--) {
			for(int j=i-1; j>=0; j--) {
				long long pos=arr[i]-arr[j];
				if(add.find(pos)!=add.end()) {
					found=distinct(add[pos], i*1000+j);
				}
				if(found) {
					res=arr[i];
					break;
				}
			}
			if(found) break;
		}
		if(found) pf("%lld\n", res);
		else pf("no solution\n");
	}

	return 0;
}
