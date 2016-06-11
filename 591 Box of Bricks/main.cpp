#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	int n, caseno=0, first=1;
	while(sc("%d", &n)==1) {
		if(n==0) break;

		int height[n], avg=0, res=0;
		for(int i=0; i<n; i++) sc("%d", &height[i]);
		for(int i=0; i<n; i++) avg+=height[i];
		avg/=n;

		for(int i=0; i<n; i++) if(height[i]>avg) res+=height[i]-avg;

		pf("Set #%d\nThe minimum number of moves is %d.\n\n", ++caseno, res);
	}

	return 0;
}
