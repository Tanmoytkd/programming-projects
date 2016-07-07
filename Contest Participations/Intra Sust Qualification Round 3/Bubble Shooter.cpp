#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int t;
	sc("%d", &t);

	for(int test=1; test<=t; test++) {
		vector<int>imax;
		int row, col;
		sc("%d %d", &row, &col);
		int arr[row][col];
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				sc("%d", &arr[i][j]);
			}
		}

		int bullet, wall;
		sc("%d %d", &bullet, &wall);

		for(int i=0; i<row; i++) {
			int left=0, right=0, spd1=wall, spd2=wall;
			for(int c=0; c<col; c++) {
				if(spd1<0) break;
				if(arr[i][c]) left++;
				else spd1--;
			}
			for(int c=col-1; c>=0; c--) {
				if(spd2<0) break;
				if(arr[i][c]) right++;
				else spd2--;
			}
			int maxi=max(left, right);
			imax.push_back(maxi);
		}

		sort(imax.begin(), imax.end());

		int total=0;

		for(int pos=imax.size()-1; pos>=0; pos--, bullet--) {
			if(bullet==0) break;
			total+=imax[pos];
		}

		pf("Case %d: %d\n", test, total);
	}
	return 0;
}
