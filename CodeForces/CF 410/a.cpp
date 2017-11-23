/*input
abcda
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int i=0, j=s.size()-1, error=0;
	while(i<j) {
		if(s[i]!=s[j]) error++;
		i++;
		j--;
	}
	if(error==1) cout << "YES" << endl;
	else if(error==0 && s.size()%2==1) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}