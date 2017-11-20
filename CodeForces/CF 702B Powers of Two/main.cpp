#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;


int main() {
	int n;
	sf1(n);
	long long int num;
	map<long long int, long long int> m;
	for(int i=0; i<n; i++) {
		cin >> num;
		m[num]++;
	}
	map<long long int, long long int>::iterator it;

	long long res=0;	

	for(it=m.begin(); it!=m.end(); it++) {
		long long int x=it->first;
		for(int i=0; i<31; i++) {
			long long tp=1<<i;
			if(tp<=x) continue;

			int diff=tp-x;
			if(diff<x) continue;
			if(x==diff) res+= m[diff]*(m[diff]-1)/2;
			else res+=m[diff]*m[x];
			if(m[diff]==0) m.erase(diff);
		}
	}
	cout << res << endl;
    return 0;
}
