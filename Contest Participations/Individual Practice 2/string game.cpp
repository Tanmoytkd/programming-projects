#include <bits/stdc++.h>
using namespace std;



map<string, int> grundy;
vector<string> dict;

int calculateGrundy(string s) {
	//cout << s << endl;
	if(s.size()==0) return 0;
	if(grundy.count(s)) return grundy[s];
	set<int> st;

	for(int i=0; i<dict.size(); i++) {
		string w = dict[i];


		for(int index=0; index<s.size(); index++) {
			int spos = s.find(w, index);
			int epos = spos+w.size();
			if(spos != -1) {
				//cout << "found " << w << endl;
				int add=0;

				if(spos>0) add^= calculateGrundy(s.substr(0, spos));
				if(epos<s.size()) add^=calculateGrundy(s.substr(epos));
				st.insert(add);
			}
		}
	}

	if(st.size()==0) {
		grundy[s]=0;
	 	return 0;
	}

	for(int i=0; i<=st.size(); i++) {
		if(st.count(i)==0) {
			grundy[s]=i;
			return i;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		grundy.clear();
		dict.clear();

		char str[50];
		scanf("%s", str);

		int n;
		scanf("%d", &n);
		char pat[50];
		for(int i=0; i<n; i++) {
			scanf("%s", pat);
			dict.push_back(pat);
		}

		int result = calculateGrundy(str);

		if(result==0) puts("Tracy");
		else puts("Teddy");



	}


}