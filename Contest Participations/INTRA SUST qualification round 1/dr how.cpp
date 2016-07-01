#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	char dna[5]="ACGT";

	long long k, n;
	while(sc("%lld %lld", &k, &n)==2) {
		int pos[k];
		for(int i=0; i<k; i++) pos[i]=0;
		
		n--;

		for(int j=k-1; j>=0; j--) {
			pos[j]=n%4;
			n/=4;
		}
		for(int i=0; i<k; i++) pf("%c", dna[pos[i]]);
		pf("\n");
	}

	return 0;	
}