/*
ID: tanmoyk2
PROG: beads
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int counter(int pos, char color) {
	int cnt=0;
	while(pos<s.size() && s[pos]==color || s[pos]=='w') {
		cnt++;
		pos++;
	}
	while(pos<s.size() && s[pos]!=color || s[pos]=='w') {
		cnt++;
		pos++;
	}

	if(cnt>n) return n;
	else return cnt;
}

int main() {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	
	cin >> n;
	
	cin >> s;
	s = s+s;

	int res=0;
	for(int i=0; i<s.size(); i++) {
		int total1 = counter(i, 'b');
		if(total1>res) res=total1;
		int total2 = counter(i, 'r');
		if(total2>res) res=total2;
	}

	cout << res << endl;
}