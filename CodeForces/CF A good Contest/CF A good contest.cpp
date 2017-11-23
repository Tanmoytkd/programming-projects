#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

bool strcheck( char str[]) {
	int len = strlen(str);
	for(int i=0; i<len; i++)
		if(!(isalpha(str[i]) || isdigit(str[i]) || str[i]=='-' || str[i]=='_')) return false;
	return true;
}

int main() {
	int n, a, b;
	bool res=false;
	char str[100];
	sc("%d", &n);

	while(n--) {
		sc("%s %d %d", str, &a, &b);
		if(!strcheck(str)) continue;
		if(a>=2400 && b>a) {
			res=true;
			break;
		}
	}

	if(res) pf("YES\n");
	else pf("NO\n");
	return 0;
}
