#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int n;
	while(sc("%d", &n) && n) {
		double data[n], sum=0, mean=0, sdv=0;
		for(int i=0; i<n; i++) {
			sc("%lf", &data[i]);
			sum+=data[i];
		}
        mean=sum/n;

        double sdv1=0, sdv2=0, diff=0;

		for(int i=0; i<n; i++) {
            diff = (double)(long)((mean-data[i])*100)/100.00;
            if(diff<0) sdv1-=diff;
            else sdv2+=diff;
		}

		if(sdv1>sdv2) sdv=sdv1;
		else sdv=sdv2;

		pf("$%.2lf\n", sdv);
	}
	return 0;
}
