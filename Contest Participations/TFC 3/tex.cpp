#include <bits/stdc++.h>
using namespace std;

int main() {
	char ch;
	int cnt=0;
	while(scanf("%c", &ch)==1) {
		if(ch=='\"') {
			cnt++;
			if(cnt&1) printf("``");
			else printf("''");
		}
		else printf("%c", ch);
	}
	return 0;
}