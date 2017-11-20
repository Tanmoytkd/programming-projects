#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	#ifdef TKD
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	for(int i=1; i<=t; i++) {
		int m, n, remove, ans;
		cin >> m >> n;
		if(m>n) {
			int temp=m;
			m=n;
			n=temp;
		}
		remove= m&1 && n&1;
		
		if(m==1) ans=n;
		else if(m==2) {
			ans=0;
			while(n) {
				if(n==1) ans+=2;
				else ans+=4;

				if(n<=4) n=0;
				else n-=4;
			}
		}
		else if(remove) {
            m--;
			ans=(m*n)>>1;
            ans+=n;
            ans-=n/2;
		}
		else {
			ans=(m*n)>>1;
		}
		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}
