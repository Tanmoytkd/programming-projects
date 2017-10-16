#include <bits/stdc++.h>
using namespace std;
#define mx 100007

string pat;
int lps[3*mx];

void kmp() {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 

int main() {
	ios::sync_with_stdio(false);
	string str, rev;
	while(cin >> str) {
		rev = str;
		reverse(rev.begin(), rev.end());

		pat = rev + "@" + str;
		kmp();
		int pos = pat.size()-1;
		//cout << lps[pos] << endl;
		int stop = rev.size() - lps[pos];
		//cout << stop << endl;
		cout << str;
		//cout << "tkd" << endl;

		while(stop--) {
			cout << str[stop];
		}
		cout << endl;
	}
	return 0;
}