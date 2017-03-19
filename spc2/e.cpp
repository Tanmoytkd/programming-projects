#include<stdio.h>
#define pf printf
#define sc scanf
#define pb push_back

int n, k, maxi=0;
int data[30];
char check[30];
int counter=0, res=0;

void calc(int p) {
    int i, j;
	if(counter==k) {
		if(res>maxi) maxi=res;
		return;
	}

	for(i=p; i<n; i++) {
		if(!check[i]) {
			check[i]=1;
			res^=data[i];
			counter++;
			calc(i+1);
			counter--;
			res^=data[i];
			for(j=i+1; j<n; j++) check[j]=0;
		}
	}
}

int main() {
	int t;
	sc("%d", &t);
	while(t--) {
        int i;
		sc("%d %d", &n, &k);
		maxi=0;
		res=0;
		for(i=0; i<n; i++) {
			sc("%d", &data[i]);
			check[i]=0;
		}
		calc(0);
		pf("%d\n", maxi);
	}

	return 0;
}
