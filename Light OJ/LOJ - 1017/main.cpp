#include <bits/stdc++.h>
using namespace std;

int n, w, k;
pair<int, int> arr[105];
int inext[105], profit[105];
int dp[100][100];

int go(int pos, int moveleft) {
	if(pos>=n) return 0;
	if(moveleft<=0) return 0;

	if(dp[pos][moveleft]==-1) {
		int res1=go(pos+1, moveleft);
		int res2=profit[pos]+go(inext[pos], moveleft-1);
		dp[pos][moveleft]=max(res1, res2);
	}
	return dp[pos][moveleft];
}


int main() {
	//freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int tst=1; tst<=t; tst++) {
		memset(dp, -1, sizeof dp);
		scanf("%d%d%d", &n, &w, &k);

		for(int i=0; i<n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			arr[i]=make_pair(y, x);
		}

		sort(arr, arr+n);

		for(int i=0; i<n; i++) {
			int y1=arr[i].first;
			int j;
			for(j=i; j<n; j++) {
				int y2=arr[j].first;
				if((y2-y1)>w) break;
			}
			inext[i]=j;
			profit[i]=j-i;
		}

		int res = go(0, k);
		printf("Case %d: %d\n", tst, res);
	}

	return 0;
}