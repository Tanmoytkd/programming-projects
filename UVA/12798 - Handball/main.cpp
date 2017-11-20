#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	int n, m;
	while(sc("%d %d", &n, &m)==2) {
		int count=0;
		for(int i=0; i<n; i++) {
			int goal=0, res=1;
			for(int j=0; j<m; j++) {
				sc("%d", &goal);
				if(goal==0) res=0;
			}
			count+=res;
		}
		cout << count << endl;
	}

	return 0;
}
