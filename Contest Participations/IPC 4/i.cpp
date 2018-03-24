#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits.h>

using namespace std;
#define N 207
int color[N], deg[N];
vector<int> edge[N];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(deg, 0, sizeof deg);
		int n, m;
		scanf("%d %d", &n, &m);

		for(int i=0; i<n; i++) edge[i].clear();

		for(int i=0; i<n; i++) {
			scanf("%d", &color[i]);
		}

		for(int i=0; i<m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			
			if(color[x]!=color[y]) {
				deg[x]++;
				deg[y]++;
				edge[x].push_back(y);
				edge[y].push_back(x);
			}
		}

		vector<int> elim;

		while(1) {
			int mxdeg = 0, mxnode=-1;

			for(int i=0; i<n; i++) {
				if(deg[i]>mxdeg) {
					mxdeg=deg[i];
					mxnode=i;
				}
			}

			if(mxdeg==0) break;

			elim.push_back(mxnode);
			deg[mxnode]=0;
			vector<int> & e = edge[mxnode];

			for(int i=0; i<e.size(); i++) {
				deg[e[i]]--;
			}
		}

		for(int i=0; i<elim.size(); i++) {
			printf("%d", elim.size());
			printf(" %d",elim[i]);
		}
		puts("");


	}
	return 0;
}