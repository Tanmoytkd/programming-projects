#include <bits/stdc++.h>
using namespace std;
#define votes first.first
#define time first.second
#define index second

#define pii pair<int, int>
#define piii pair<pii, int>

piii arr[107];
int result[107];

int cmp(piii a, piii b) {
	return a>b;
}

int main() {
	int n, k, m, a;
	scanf("%d %d %d %d", &n, &k, &m, &a);

	for(int i=1; i<=n; i++) arr[i].index = i;

	for(int i=1; i<=a; i++) {
		int g;
		scanf("%d", &g);

		arr[g].votes++;
		arr[g].time=0-i;
	}

	sort(arr+1, arr+(n+1), cmp);



	for(int i=1; i<=n; i++) {
		int vote = arr[i].votes;
		int pos = arr[i].index;
		int tm = arr[i].time;
		// cout << pos << endl;
		
		if(i<=k) {
			if(vote!=0) {
				result[pos]=2;
				if(n==k) result[pos]=1;
				int needvote = 0;
				for(int j=i+1; j<=min(k+1, n); j++) {
					needvote+=vote - arr[j].votes+1;
					//if(tm>arr[j].time && vote == arr[j].votes) needvote++;
				}
				//cout << pos << " " << needvote << endl;
				if(needvote>(m-a)) result[pos]=1;
			}
			else {
				if(a<m) {
					result[pos]=2;
					if(n==1) result[pos]=1;
				}
				else {
					result[pos]=3;
				}

			}
		}
		else {
			result[pos]=3;
			int needvote = arr[k].votes-vote+1;
			
			if(needvote<=(m-a)) result[pos]=2;
		}
	}

	for(int i=1; i<=n; i++) {
		printf("%d%c", result[i], " \n"[i==n]);
	}

	return 0;
}