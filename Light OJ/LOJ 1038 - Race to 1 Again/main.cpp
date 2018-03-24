#include <bits/stdc++.h>
using namespace std;

vector<int> divisors[100007];
double moves[100007];


int main() {
	for(int i=2; i<=100000; i++) {
		for(int j=i; j<=100000; j+=i) {
			divisors[j].push_back(i);
		}
	}

	moves[1]=0;
	for(int num=2; num<=100000; num++) {
		vector<int> & d = divisors[num];
		int div=d.size();
		double sum = 0;
		for(int i=0; i<d.size(); i++) {
			int x = d[i];
			sum+=moves[x];
		}
		moves[num] = (double) (div+1)/div + sum/div;
	}

	int t;
	scanf("%d", &t);

	for(int tst=1; tst<=t; tst++) {
		int n;
		scanf("%d", &n);

		printf("Case %d: %.10lf\n", tst, moves[n]);
		//cout << moves[n] << endl;
	}

	return 0;
}