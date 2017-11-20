#include<bits/stdc++.h>
using namespace std;

//ei function a ekta string er vitore rakha number 11 diye divisible kina ta check korbe
int divisible_by_11(string s) {
	int sum=0;
	int i;
	for(i=0; i<s.size(); i++) {
		if(s[i]=='-') continue; //jodi number ta negative hoy tahole - sign ta baad dibe
		
		int digit = s[i]-'0';
		if(i%2==0) sum=sum+digit;
		else sum=sum-digit;
	}
	if(sum%11==0) return 1;
	else return 0;
}

//ei function a ekta character array er vitore rakha number 11 diye divisible kina ta check korbe
int divisible_by_11(char s[]) {
	int sum=0;
	int i, len=strlen(s);
	for(i=0; i<len; i++) {
		if(s[i]=='-') continue; //jodi number ta negative hoy tahole - sign ta ignore korbe

		int digit = s[i]-'0';
		if(i%2==0) sum=sum+digit;
		else sum=sum-digit;
	}
	if(sum%11==0) return 1;
	else return 0;
}

//ei function ta ekta long long variable 11 diye divisible kina eita check korbe
int divisible_by_11(long long n) {
	if(n%11==0) return 1;
	else return 0;
}

int main()
{
    int t, tst = 1;
    string x="10516";
    string y="771";

    if(divisible_by_11(x)==1) {
    	cout << x << " is divisible by 11" << endl;
    }

    if(divisible_by_11(y)==0) {
    	cout << y << " is not divisible by 11" << endl;
    }
    
    return 0;
}
