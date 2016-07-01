#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	string line, str;
	while(1) {
		getline(cin, line);

		if(line=="#") break;
		bool sm=false, first=true;
		stringstream ss(line);
		while(ss >> str) {
			if(sm) {
				sm=false;
			}
			else {
				if(str[0]==':' || str[0]=='-' || str[0]=='>') sm=true;

				if(first) first=false;
				else cout << " ";

				cout << str;
			}
		}
		cout << endl;
	}
	return 0;
}
