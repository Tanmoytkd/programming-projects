#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	char str[10000];
	while(gets(str)!=NULL) {
		int len=strlen(str);
		if(!isdigit(str[0])) {
			for(int pos=len-1; pos>=0; pos--) {
				int num=str[pos];
				while(num) {
					pf("%d", num%10);
					num/=10;
				}
			}
		}
		else {
			reverse(str, str+len);
			int pos=0;
			char num[4];
			while(pos!=len) {
				if(str[pos]=='1') {
					strncpy(num, str+pos, 3);
					num[3]=0;
					pos+=3;
				}
				else {
					strncpy(num, str+pos, 2);
					num[2]=0;
					pos+=2;
				}
				int number=atoi(num);
				pf("%c", number);
			}
		}
		pf("\n");
	}
	return 0;
}
