#include <bits/stdc++.h>
using namespace std;

string str;
int dig[100];


int main() {
	int t, digit;
	cin >> t;
	for(int test=1; test<=t; test++) {
		cin >> str;
		int len = str.size();

		memset(dig, -1, sizeof dig);
		if(str[0]>='0' && str[0]<='9') {
			dig[str[0]-'0']=1;
		}
		else {
			dig[str[0]-'a'+10]=1;
		}
		int nxtdigit=0;
		str[0]=1;
		for(int i=1; i<len; i++) {
			if(str[i]>='0' && str[i]<='9')
				digit = str[i]-'0';
			else digit=str[i]-'a'+10;
			if(dig[digit]==-1)
			{
				dig[digit]=nxtdigit;
				if(!nxtdigit) nxtdigit=2;
				else nxtdigit++;
			}
			str[i]=dig[digit];
		}
		int base = 10;
		long long value = 0;
		if(nxtdigit<=2)
			base=2;
		else base=nxtdigit;
		value=0;
		for(int i=0; i<len; i++) {
			value = value*base + str[i];
		}
		cout << "Case #" << test << ": " << value << endl;
	}
	return 0;
}
