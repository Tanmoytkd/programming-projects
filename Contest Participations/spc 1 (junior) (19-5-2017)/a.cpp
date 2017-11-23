#include <bits/stdc++.h>
using namespace std;
#define lint long long int

int  main() {
    lint t,n,num,k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		lint s=0;
		for(int i=1; i<=n; i++) {
			cin >> num;
			if (num<k) s += k-num;
			else {
				num%=k;
				s+=min(num, k-num);
			}
		}
		cout << s << endl;
	}
	return 0;
}
