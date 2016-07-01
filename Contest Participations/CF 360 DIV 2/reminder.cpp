#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;
#define MXN 1000001

int check[MXN];
std::vector<int> prime;

void sieve() {
	prime.pb(2);
	for(int i=3; i*i<=MXN; i+=2) {
		if(!check[i]) {
			prime.pb(i);
			for(int j=i+i; j<=MXN; j+=i) {
				check[j]=1;
			}
		}
	}
}

int main() {

	int n, k, num, i=0;
	cin >> n >> k;
	set<int> ancient;
	while(n--) {
		cin >> num;
		if(num==k) { cout << "Yes" << endl; return 0;}
		ancient.insert(num);
	}

	set<int>::iterator it=ancient.end();
	it--;
	for(; ; it--) {
		int number=*it;
		while(k%number==0) k/=number;
		if(k==1) break;
		if(it==ancient.begin()) break;
	}

	if(k==1) cout << "Yes" << endl;
	else cout << "No" << endl;


	return 0;
}
