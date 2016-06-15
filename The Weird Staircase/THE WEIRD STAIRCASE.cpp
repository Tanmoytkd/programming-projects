#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int n, mini=INT_MAX, data[30], check[30], moves=0;

void run(int i) {
	if(i<0) return;
	else if(check[i]==1) return;
	else if(i>n) return;
	else if(i==n) {
		if(moves<mini) mini=moves;
		return;
	}

	check[i]=1;
	moves++;
	run(i+data[i]);
	run(i+1);
	moves--;
	check[i]=0;
}

int main() {
	int t;
	sc("%d", &t);

	while(t--) {
		mini=INT_MAX;
		sc("%d", &n);
		for(int i=0; i<n; i++) {
			sc("%d", &data[i]);
		}
		run(0);
		if(mini==INT_MAX) pf("-1\n");
		else pf("%d\n", mini);
	}

	return 0;
}
