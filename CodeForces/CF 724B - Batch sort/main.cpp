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


int n, m;
int arr[22][22];

void colswap(int i, int j) {
	for(int row=0; row<n; row++)
		swap(arr[row][i], arr[row][j]);
}

int rowcheck() {
	for(int i=0; i<n; i++) {
		int err=0;
		for(int j=0; j<m; j++) {
			if(arr[i][j]!=j+1) err++;
		}
		if(err>2) return 0;
	}
	return 1;
}

int main() {
    int res=0;
	sf2(n,m);
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++) {
		sf1(arr[i][j]);
	}
	
	if(rowcheck()) res=1;

	if(!res) {
		for(int i=0; i<m; i++) {
			if(res) break;
			for(int j=i+1; j<m; j++) {
				colswap(i,j);
				if(rowcheck()) {
					res=1;
					break;
				}
				colswap(i,j);
			}
		}
	}
	
	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;	
    return 0;
}
