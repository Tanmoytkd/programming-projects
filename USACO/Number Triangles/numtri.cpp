/*
ID: tanmoyk2
PROG: numtri
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
int dp[1007][1007], a[1007][1007];
int row;

int go(int r, int c) {
	if(r==row-1) return a[r][c];
	if(dp[r][c]==-1) {
		int & ans = dp[r][c];
		ans=a[r][c];
		ans+=max(go(r+1, c), go(r+1, c+1));		
	}
	return dp[r][c];
}

int main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	fin >> row;
	for(int i=0; i<row; i++) {
		for(int j=0; j<=i; j++) {
			fin >> a[i][j];
		}
	}

	memset(dp, -1, sizeof dp);

	int res = go(0, 0);

	fout << res << endl;	
	return 0;
}

/*
9-bba
10-12: algo lab (for contestants)
12-1:stat
2-3:30: DLD
*/