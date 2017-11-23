/*input
5
1 2 b
2 3 r
3 4 r
4 5 b
*/
#include<bits/stdc++.h>
using namespace std;
#define mx 100007
#define mod 1000000007
typedef long long lint;
#define pb push_back

std::vector<int> edge[mx];
int visit[mx], cnt[mx];

void dfs(int node, int hasparent) {
	if(hasparent) cnt[node]++;
	visit[node]=1;
	std::vector<int> & e = edge[node];
	for(int i=0; i<e.size(); i++) {
		int newnode=e[i];
		if(visit[newnode]) continue;
		cnt[node]++;
		dfs(newnode, 1);
	}
}

lint ncr[mx];

int main() {
	ncr[0]=0;
	ncr[1]=0;
	for(lint i=2; i<mx; i++) ncr[i]=(i*(i-1)/2)%mod;

	int n;
	cin >> n;

	for(int i=0; i<n-1; i++) {
		int a, b;
		string s;

		cin >> a >> b >> s;
		if(s[0]=='r') {
			edge[a].pb(b);
			edge[b].pb(a);
		}
	}

	lint res=0;
	for(int i=1; i<=n; i++) {
		if(visit[i]) continue;
		dfs(i, 0);
	}

	for(int i=1; i<=n; i++) {
		int total=cnt[i];
		res+=ncr[i];
	}
	cout << res << endl;
	return 0;
}