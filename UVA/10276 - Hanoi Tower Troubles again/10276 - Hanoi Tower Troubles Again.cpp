#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int sqr(int num) {
	int temp=sqrt(num);
	if(temp*temp==num) return 1;
	return 0;
}

int maxi=0, n;
std::vector<int> v[50];

void hanoi(int p) {
	int i;
	for(i=0; i<n; i++) {
        if(maxi>0) return;
		if(v[i].empty()) {
			v[i].pb(p);
			hanoi(p+1);
			break;
		}
		int top=v[i].back()+p;
		if(sqr(top)) {
			v[i].pb(p);
			hanoi(p+1);
			v[i].Pb();
		}
	}

	p--;
	if(i==n && p>maxi) {
		maxi = p;
	}
}

int main() {
	int t;
	sc("%d", &t);

	while(t--) {
		sc("%d", &n);
		maxi=0;
		for(int i=0; i<n; i++) v[i].clear();
		hanoi(1);
		pf("%d\n", maxi);
	}

	return 0;
}
