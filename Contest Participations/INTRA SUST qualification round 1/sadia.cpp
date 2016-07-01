#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	long long t, n;
	cin >> t;

	while(t--) {
		std::map<long long, long long> check;
		long long x, y, counter=0;
		cin >> x >> y;
		long long x1, y1, dist;
		cin >> n;
		while(n--) {
			cin >> x1 >> y1;
			dist=(x-x1)*(x-x1)+(y-y1)*(y-y1);
			if(check.find(dist)==check.end()) {
				counter++;
				check[dist]=1;
			}
		}
		cout << counter << endl;
	}
	return 0;
}
