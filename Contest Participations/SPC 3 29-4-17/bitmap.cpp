#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int level[200][200];
int fx[4] = {1, -1, 0, 0}, fy[4]={0, 0, 1, -1};

int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(level, 0, sizeof level);
		int n, m;
		

		cin >> n >> m;
		string arr[n];

		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}

		for(int i=0; i<n; i++) {
			cout << arr[i] << endl;
		}

		queue<pair<int, int> > q;

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(arr[i][j]=='1') {
					q.push(make_pair(i,j));
					level[i][j]=1;
				}
			}
		}

		while(!q.empty()) {
			pii a=q.front();
			int row = a.first, col=a.second;
			q.pop();

			for(int i=0; i<4; i++) {
				int newrow = row+fx[i];
				int newcol = col+fy[i];

				if(newrow<0 || newrow>=n || newcol<0 || newcol>=m) continue;

				if(level[newrow][newcol]==0 || level[newrow][newcol]>(level[row][col]+1)) {
					level[newrow][newcol]=level[row][col]+1;
					q.push(make_pair(newrow, newcol));
				}
			}
		}

		

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cout << level[i][j]-1 << " \n"[j==m-1];
			}
		}

	}
	return 0;
}
