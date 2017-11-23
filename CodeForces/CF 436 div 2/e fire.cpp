#include <bits/stdc++.h>
using namespace std;

int dp[150][2500], ds[150][2500];
int n;

struct data {
	int t, d, p, index;
	data(int t, int d, int p, int index) :t(t), d(d), p(p), index(index) {}
};

bool comp(data a, data b) {
	if(a.d==b.d) return a.t<b.t;
	return a.d<b.d;
}

std::vector<data> v;
vector<int> res, vec;

int rec(int pos, int t) {
	if(pos==n) return 0;
	if(dp[pos][t]==-1) {
		data d = v[pos];
		ds[pos][t]=0;
		int res1 = rec(pos+1, t);
		dp[pos][t]=res1;
		if(t+d.t<d.d) {
			int res2 = d.p + rec(pos+1, t+d.t);
			if(res2>res1) {
				dp[pos][t]=res2;
				ds[pos][t]=1;
			}
		}
	}
	return dp[pos][t];
}

vector<int> rest;

void sout(int pos, int t) {
	if(pos==n) return;
	if(ds[pos][t]==1) {
		rest.push_back(v[pos].index); 
		sout(pos+1, t+v[pos].t);
		return;
	}
	sout(pos+1, t);
}

int main() {
	
	cin >> n;

	for(int i=0; i<n; i++) {
		int t, d, p;
		cin >> t >> d >> p;
		v.push_back(data(t, d, p, i+1));
	}

	sort(v.begin(), v.end(), comp);

	
	memset(dp, -1, sizeof dp);
	cout << rec(0, 0) << endl;

	sout(0, 0);
	cout << rest.size() << endl;
	for(int i=0; i<rest.size(); i++) {
		if(i) cout << " ";
		cout << rest[i];
	}
	cout << endl;

	return 0;
}