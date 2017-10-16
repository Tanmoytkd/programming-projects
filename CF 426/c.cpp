/*input
7
1 1
2 4
75 45
8 8
16 16
247 994
1000000000 1000000
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 31700
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
	//cout << p.size() << endl;
	int n;
	scanf("%d", &n);
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		long long check = a;
		check=check*b;
		int possible=1;
		for(int i=0; i<p.size(); i++) {
			int prime = p[i];

			
			int cnt=0;
			if(check%prime==0 && (a%prime!=0 || b%prime!=0)) {
				possible=0;
				break;
			}

			while(check%prime==0) {
				cnt++;
				check/=prime;
			}
			
			// if(cnt)
			// cout << prime << " " << cnt << endl;

			if((cnt%3)!=0) {
				possible=0;
				break;
			}
		}
		if(check>1) possible=0;

		if(possible) puts("Yes");
		else puts("No");
	}
	return 0;
}