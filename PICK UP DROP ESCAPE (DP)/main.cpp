#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int n, k, maxi=INT_MIN;
int data[30];
bool check[30];
int counter=0, res=0;

void calc() {
	if(counter==k) {
		if(res>maxi) maxi=res;
		return;
	}

	for(int i=0; i<n; i++) {
		if(!check[i]) {
			check[i]=true;
			res^=data[i];
			counter++;
			calc();
			counter--;
			res^=data[i];
			for(int j=i+1; j<n; j++) check[j]=false;
		}
	}
}

int main() {
	int t;
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &k);
		maxi=INT_MIN;
		res=0;
		for(int i=0; i<n; i++) {
			sc("%d", &data[i]);
			check[i]=false;
		}
		calc();
		pf("%d\n", maxi);
	}

	return 0;
}