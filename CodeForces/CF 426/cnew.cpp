/*input
6
2 4
75 45
8 8
16 16
247 994
1000000000 1000000
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 31623
vector<int> p;

int comp[mx+1];
void seive() {
	int stop = sqrt(mx);
	for(int i=3; i<=stop; i+=2) {
		if(comp[i]) continue;
		for(int j=i*i; j<=mx; j+=i+i) {
			comp[j]=1;
		}
	}

	p.push_back(2);
	for(int i=3; i<=mx; i+=2) {
		if(comp[i]) continue;
		p.push_back(i);
	}
}



int main() {
	seive();
	int n;
	scanf("%d", &n);
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int possible=1;
		for(int i=0; i<p.size(); i++) {
			int prime = p[i];

			if(prime>a || prime>b) break;
			
			int cnt1=0, cnt2=0;
			while(a%prime==0) {
				cnt1++;
				a/=prime;
			}
			while(b%prime==0) {
				cnt2++;
				b/=prime;
			}
			
			if(cnt1>cnt2) {
				swap(cnt1, cnt2);
			}

			if(cnt1==0 && cnt2!=0) {
				possible=0;
				break;
			}

			if((cnt1*2)<cnt2) {
				possible=0;
				break;
			}

			if((cnt1+cnt2)%3!=0) {
				possible=0;
				break;
			}
		}
		long long A=a, B=b;
		if(A>B) swap(A, B);
		if((A>1 || B>1) && A*A!=B) possible=0;

		if(possible) puts("Yes");
		else puts("No");
	}
	return 0;
}