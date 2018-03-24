#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int tst=1;tst<=t;tst++) {
		char str[100];
		scanf("%s", str);
		int len = strlen(str);
		stack<char> st;
		int cnt[256];
		memset(cnt, 0, sizeof cnt);
		cnt[str[0]]--;
		for(int i=0; i<len; i++) {
			if(st.empty()) {
				st.push(str[i]);
			}
			else {
				cnt[st.top()]++;
				if(str[i]==st.top()) st.pop();
				else st.push(str[i]);
			}
		}

		printf("Case %d\n", tst);

		for(int ch = 'A'; ch<='Z'; ch++) {
			if(cnt[ch])
				printf("%c = %d\n", ch, cnt[ch]);
		}
	}
	return 0;
}