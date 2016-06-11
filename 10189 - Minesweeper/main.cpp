#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int m, n, caseno=0, first=1;
	while(cin >> m >> n) {
        if(m==0 && n==0) break;
		int data[m+2][n+2];
		for(int i=0; i<m+2; i++)
			for(int j=0; j<n+2; j++)
				data[i][j]=0;

		char ch;
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				cin >> ch;
				while(ch!='*' && ch!='.') cin >> ch;
				if(ch=='*') {
					data[i][j]=ch-1;
					for(int p=i-1; p<=i+1; p++) {
						for(int q=j-1; q<=j+1; q++) {
							if(data[p][q]!='*') data[p][q]++;
						}
					}
				}
			}
		}

        if(!first) 	pf("\n");
        else first=0;

		pf("Field #%d:\n", ++caseno);
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				if(data[i][j]=='*') pf("*");
				else pf("%d", data[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
