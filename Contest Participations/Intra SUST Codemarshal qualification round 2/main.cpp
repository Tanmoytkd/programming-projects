#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back
#define Pb pop_back

using namespace std;

int main() {
	long long t;
	cin >> t;

	while(t--) {
		map<long long, long long> m;
		long long n;
		cin >> n;
		long long a, b, c;
		while(n--) {
			cin >> a >> b >> c;
			a*=1000000000;
			long double tand= (long double) a/b;
			long long tang= llround(tand);
			if(m.find(tang)!=m.end()) m[tang]++;
			else m[tang]=1;

		}

		long long res=1;

		long long mod=1;
		for(int i=0; i<9; i++) mod*=10;
		mod+=7;

		map<long long, long long>::iterator it=m.begin(), ite=m.end();
		for(;it!=ite; it++) {
			long long num=it->second;
			num%=mod;
			res*=num;
			res%=mod;
		}

		cout << res << endl;
	}

	return 0;

}
