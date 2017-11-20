#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	int t, n;
	sc("%d", &t);
	for(int i=1; i<=t; i++) {
		sc("%d", &n);
		int pos, count=0, res=-1;
		char data[3];
		for(pos=1; pos<=n; pos++) {
			sc("%s", data);
			if(data[0]=='W') count=0;
			else count++;

			if(count==3 && res==-1) res=pos;
		}

		pf("Case %d: ", i);
		if(res==-1) cout << "Yay! Mighty Rafa persists!" << endl;
		else cout << res << endl;
	}

	return 0;
}
