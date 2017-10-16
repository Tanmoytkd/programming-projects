#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	string xmove="", ymove="";

	int xm=s[0]-t[0];
	int ym=s[1]-t[1];

	string res="";
	int cnt=0;

	while(xm!=0 || ym!=0) {
		if(xm<0) {
			res+="R";
			xm++;
		}
		else if(xm>0) {
			res+="L";
			xm--;
		}

		if(ym>0) {
			res+="D";
			ym--;
		}
		else if(ym<0) {
			res+="U";
			ym++;
		}
		res+='\n';
		cnt++;
	}

	cout << cnt << endl << res;
	return 0;
}