/*
ID: tanmoyk2
PROG: runround
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> v;

void generate(long long m) {
	v.clear();
	while(m) {
		v.push_back(m%10);
		m/=10;
	}
	reverse(v.begin(), v.end());
}

bool is_runround() {
	vector<int> mark(v.size(), 0);
	vector<int> digit(10, 0);
	int pos=0;
	int cnt=0;
	while(mark[pos]==0 && digit[v[pos]]==0) {
		mark[pos]=1;
		digit[v[pos]]=1;
		cnt++;
		pos = (pos+v[pos])%v.size();
	}

	//cout << pos << endl;
	return (cnt==v.size()) && (pos==0);
}

int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);

	long long m;
	cin >> m;

	do {
		m++;
		generate(m);
		//cout << m << " ";
	}while(!is_runround());

	cout << m << endl;

	return 0;
}