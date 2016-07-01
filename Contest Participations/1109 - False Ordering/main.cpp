#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

struct number {
	int num;
	int divisor;

	number() {
        num=0;
        divisor=0;
	}

	bool operator< (number b) {
        return divisor<b.divisor || (divisor==b.divisor && num>b.num);
	}
};

struct number data[1001];

int main() {
	for(int i=0; i<1001; i++) data[i].num=i;

	for(int i=1; i<=1000; i++) {
		for(int j=i; j<=1000; j+=i) {
			data[j].divisor++;
		}
	}

	for(int i=1; i<1000; i++) {
		for(int j=i+1; j<=1000; j++) {
			if(data[j]<data[i]) {
				struct number temp=data[j];
				data[j]=data[i];
				data[i]=temp;
			}
		}
	}

	int test;
	cin >> test;

	for(int t=1; t<=test; t++) {
		int pos;
		cin >> pos;
		pf("Case %d: %d\n", t, data[pos].num);
	}
	return 0;
}
