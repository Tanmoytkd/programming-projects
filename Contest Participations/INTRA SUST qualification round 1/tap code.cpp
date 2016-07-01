#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

string conv(char ch) {
	string result;
	switch(ch) {
		case 'a': result=".,."; break;
		case 'b': result=".,.."; break;
		case 'c': 
		case 'k': result=".,..."; break;
		case 'd': result=".,...."; break;
		case 'e': result=".,....."; break;
		
		case 'f': result="..,."; break;
		case 'g': result="..,.."; break;
		case 'h': result="..,..."; break;
		case 'i': result="..,...."; break;
		case 'j': result="..,....."; break;

		case 'l': result="...,."; break;
		case 'm': result="...,.."; break;
		case 'n': result="...,..."; break;
		case 'o': result="...,...."; break;
		case 'p': result="...,....."; break;
		
		case 'q': result="....,."; break;
		case 'r': result="....,.."; break;
		case 's': result="....,..."; break;
		case 't': result="....,...."; break;
		case 'u': result="....,....."; break;
		
		case 'v': result=".....,."; break;
		case 'w': result=".....,.."; break;
		case 'x': result=".....,..."; break;
		case 'y': result=".....,...."; break;
		case 'z': result=".....,....."; break;
		default: result="";
	}
	return result;
}

int main() {
	int t;
	string s, res;
	cin >> t;
	for(int test=1; test<=t; test++) {
		cin >> s;
		pf("Case %d: ", test);
		int len=s.length();
		for(int i=0; i<len; i++) {

			res=conv(s[i]);

			cout << res;

			if(i==len-1) pf("\n");
			else pf(" ");
		}
	}
	return 0;	
}