/*input
5
3123 3123
2777 2777
2246 2246
2246 2246
1699 1699
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sure=0, change=0;
	int imin=INT_MAX;
	while(n--) {
		int a, b;
		cin >> a >> b;

		if(a!=b) change=1;

		if(b>imin) sure=1;
		else imin=b;
	}

	if(change) cout << "rated" << endl;
	else if(sure) cout << "unrated" << endl;
	else cout << "maybe" << endl;
	return 0;
}