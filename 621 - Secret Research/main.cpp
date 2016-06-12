#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

int main() {
	int n;
	string s;
	sc("%d", &n);

	while(n--) {
		cin >> s;
		int len=s.length();
		if(s=="1" || s=="4" || s=="78") pf("+\n");
		else if(s[len-2]=='3' && s[len-1]=='5') pf("-\n");
		else if(s[0]=='9' && s[len-1]=='4') pf("*\n");
		else if(s[0]=='1' && s[1]=='9' && s[2]=='0') pf("?\n");		
	}

	return 0;
}
