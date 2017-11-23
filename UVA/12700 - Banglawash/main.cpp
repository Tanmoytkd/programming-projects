#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	int t, n;
	sc("%d", &t);
	for(int i=1; i<=t; i++) {
		sc("%d", &n);

		char data[n+1];

		sc("%s", data);

		int B=0, W=0, T=0, A=0;
		for(int j=0; j<n; j++) {
			if(data[j]=='B') B++;
			else if(data[j]=='W') W++;
			else if(data[j]=='T') T++;
			else if(data[j]=='A') A++;
		}
		
		if(A==n)
        	printf("Case %d: ABANDONED\n",i);
 	    else if(B==W)
        	printf("Case %d: DRAW %d %d\n",i,B,T);
    	else if(B+A==n)
        	printf("Case %d: BANGLAWASH\n",i);
    	else if(W+A==n)
    	    printf("Case %d: WHITEWASH\n",i);
    	else if(B>W)
	        printf("Case %d: BANGLADESH %d - %d\n",i,B,W);
    	else if(W>B)
        	printf("Case %d: WWW %d - %d\n",i,W,B);
	}

	return 0;
}
