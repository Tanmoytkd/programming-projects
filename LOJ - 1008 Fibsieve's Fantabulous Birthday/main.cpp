#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int test=1; test<=t; test++) {
		long long n;
		cin >> n;
		cout << "Case " << test << ": ";
		long long sqt=sqrt(n), rowpos, colpos;
		
		if(sqt*sqt==n) {
			if(sqt&1) cout << 1 << " " << sqt << endl;
			else cout << sqt << " " << 1 << endl;
		}
		else {
			rowpos=sqt+1, colpos=sqt+1;
			n=n-sqt*sqt;

			if(sqt&1) {
				if(n<colpos) colpos=n;
				else if(n>colpos) rowpos-=n-rowpos;
			}
			else {
				if(n<rowpos) rowpos=n;
				else if(n>rowpos) colpos-=n-colpos;
			}
		cout << colpos << " " << rowpos << endl;
		}
		
	}

	return 0;
}
