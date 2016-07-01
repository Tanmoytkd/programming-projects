#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	string s1, s2;
	int i=0, j=0, l1=0, l2=0;
	cin >> s1 >> s2;
	l1=s1.length();
	l2=s2.length();

	while(i<l1 && s1[i]=='0') i++;
	while(j<l2 && s2[j]=='0') j++;

	while(s1[i]==s2[j]) {
		if(i==l1 || j==l2) break;
		i++;
		j++;
	}

	int res=s1.length()-i+s2.length()-j;
	cout << res << endl;
	return 0;
}
