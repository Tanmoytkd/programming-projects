#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int n, a, maxi=0;
std::set<int> like[21], dislike[21];
std::vector<int> current;

void rec(int pos) {
    int currsize=current.size();

    if(pos==n+1) {
        if(currsize>maxi) {
            set<int> curlike;
            for(int i=0; i<currsize; i++) {
                curlike.insert(current[i]);
                set<int> &element=like[current[i]];
                curlike.insert(element.begin(), element.end());
            }

            if(curlike.size()==currsize)
                maxi=currsize;
        }
    	return;
    }

    int conflict=0;
    rec(pos+1);

    for(int i=0; i<currsize; i++) {
        if(dislike[current[i]].find(pos)!=dislike[current[i]].end()) conflict=1;
        if(dislike[pos].find(current[i])!=dislike[pos].end()) conflict=1;
    }
    if(dislike[pos].find(pos)!=dislike[pos].end()) conflict=1;

    if(!conflict) {
        current.pb(pos);
        rec(pos+1);
        current.Pb();
    }

}

int main() {
	while(sc("%d %d", &n, &a)==2) {
        if(n==0 && a==0) break;

		for(int i=1; i<=n; i++) {
			like[i].clear();
			dislike[i].clear();
		}
		int u, v;
		for(int i=0; i<a; i++) {
			sc("%d %d", &u, &v);
			if(v>0) like[u].insert(v);
			else dislike[u].insert(0-v);
		}
		maxi=0;
		rec(1);
		cout << maxi << endl;
	}
	return 0;
}
