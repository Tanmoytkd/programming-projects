#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	string str;
	bool sm=false;
	while(cin >> str) {
		if(str=="#") {
			cout << endl;
			break;
		} 
		if(sm) {
			sm=false;
		}
		else {
			if(str[0]==':' || str[0]=='-' || str[0]=='>') sm=true;
			cout << str << " ";
		}
	}
	return 0;	
}