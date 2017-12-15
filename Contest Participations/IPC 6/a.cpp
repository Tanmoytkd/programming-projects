#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define piii pair< pii, int >
#define position first.first
#define type first.second
#define index second

int main() {
	int n;
	scanf("%d", &n);
	stack<int> st;
	st.push(-1);

	vector<piii> v;
	for(int i=1; i<=n; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		piii start, finish;
		start.position=a;
		start.type=0;
		start.index=i;
		v.push_back(start);

		finish.position=b+1;
		finish.type=-1;
		finish.index=i;
		v.push_back(finish);
	}

	int m;
	scanf("%d", &m);

	int res[m];

	for(int i=0; i<m; i++) {
		int pos;
		scanf("%d", &pos);
		piii x = make_pair(make_pair(pos, 2), i);
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for(int i=0; i<v.size(); i++) {
		piii x = v[i];
		if(x.type==0) {
			st.push(x.index);
		}
		if(x.type==-1) {
			st.pop();
		}
		if(x.type==2) {
			res[x.index]=st.top();
		}
	}

	for(int i=0; i<m; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}