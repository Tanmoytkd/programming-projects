#include <bits/stdc++.h>
using namespace std;

long long w, m;
map<long long, long long> mp;

long long possible=0;

vector<long long> val;

void igenerate(long long pos, long long current, long long fin) {
	
	if(pos>=fin) {
		//cout << current << endl;
		mp[m-current]=1;
		return;
	}

	igenerate(pos+1, current+val[pos], fin);
	igenerate(pos+1, current, fin);
	igenerate(pos+1, current-val[pos], fin);
}

void check(long long pos, long long current) {
	if(pos==val.size()) {
		if(mp.count(current)) possible=1;
		return;
	}

	check(pos+1, current+val[pos]);
	check(pos+1, current);
	check(pos+1, current-val[pos]);
}

int main() {
	scanf("%I64d %I64d", &w, &m);

	if(w==2) {
		cout << "YES" << endl;
		return 0;
	}

	long long product=1;
	for(product=1; product<=m; product*=w) {
		if(product>0) val.push_back(product);
		else break;
	}

	if(product>0) val.push_back(product);
	if(product<=(LLONG_MAX)/w && val.size()<32) val.push_back(product*w);
	
	//cout << val.size() << endl;

	//cout << val.size() << endl;

	// for(long long i=0; i<val.size(); i++) cout << val[i] << " ";
	// 	cout << endl;

	igenerate(0, 0, val.size()/2);

	//cout << mp.size() << endl;

	//for(map<long long, long long>::iterator it = mp.begin(); it!=mp.end(); it++) cout << it->first << endl;


	check(val.size()/2, 0);

	if(possible) cout << "YES" << endl;
	else cout << "NO" << endl;

}