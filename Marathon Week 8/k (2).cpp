#include <bits/stdc++.h>
using namespace std;

int sum(string& x) {
	int res=0;
	for(int i=0; i<x.size(); i++) res+=x[i]-'0';
	return res;
}

int main() {
	string x;
	cin >> x;
	string temp = x;

	string res=x;
	int mx=sum(x);	

	for(int i=x.size()-1; i>=1; i--) {
		temp[i]='9';
		if(temp[i-1]>'0') {
			temp[i-1]--;
			if(sum(temp)>mx) {
				mx = sum(temp);
				res=temp;
			}
		}

	}

	if(res[0]=='0') {
		res = res.substr(1);
	}

	cout << res << endl;

	return 0;
}