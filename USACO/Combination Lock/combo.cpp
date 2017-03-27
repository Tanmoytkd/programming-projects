/*
ID: tanmoyk2
PROG: combo
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> code, master, v;
int n, res=0;

int match(const vector<int>& v, const vector<int>& code) {
	for(int i=0; i<v.size(); i++) {
		int a=v[i], b=code[i];
		if(a<b) swap(a,b);

		int diff=a-b;
		diff = min(diff, b+n-a);
		if(diff>2) return 0;
	}
	return 1;
}

void go(int pos) {
	if(pos==3) {
		if(match(v, code) || match(v, master)) {
			res++;
		}
		return;
	}

	for(int i=1; i<=n; i++) {
		v.push_back(i);
		go(pos+1);
		v.pop_back();
	}
}

int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");


    fin >> n;
    //cout << n ;
    int a,b,c,d,e,f;
    fin >> a >> b >> c >> d >> e >> f;
    //cout << a << b << c << d << e << f;

    int pat[3], mas[3];
    code.push_back(a);
    code.push_back(b);
    code.push_back(c);

    master.push_back(d);
    master.push_back(e);
    master.push_back(f);

    go(0);

    fout << res << endl;

    return 0;
}
