/*
ID: tanmoyk2
PROG: sort3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int n;
	fin >> n;
	int cnt[4];
	memset(cnt, 0, sizeof cnt);
	int arr[n];
	for(int i=0; i<n; i++) fin >> arr[i];

	for(int i=0; i<n; i++) cnt[arr[i]]++;

	cnt[2]+=cnt[1];
	cnt[3]+=cnt[2];

	int edge[4][4];
	memset(edge, 0, sizeof edge);

	int j=0, error=0;
	for(int i=1; i<=3; i++) {
		for(; j<cnt[i]; j++) {
			int dig=arr[j];
			if(dig!=i) error++;
			edge[i][dig]++;
		}
	}


	int res=0;
	for(int i=1; i<=3; i++) {
		for(int j=i+1; j<=3; j++) {
			int cost=min(edge[i][j], edge[j][i]);
			//cout << "cost between " << i << " and " << j << " is " << cost << endl;
			res+=cost;
			error-=cost*2;
		}
	}

	//cout << error << endl;
	res+= error/3*2;
	fout << res << endl;
	return 0;
}