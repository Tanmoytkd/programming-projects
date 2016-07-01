#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;

	string allpresent="";
	for(int i=0; i<n; i++) allpresent+="1";

	string data;
	int counter=0, maxi=0;

	while(d--) {
		cin >> data;
		if(data!=allpresent) counter++;
		else {
			if(counter>maxi) maxi=counter;
			counter=0;
		}
	}
	if(counter>maxi) maxi=counter;

	cout << maxi << endl;
	return 0;
}
