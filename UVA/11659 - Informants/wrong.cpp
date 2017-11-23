#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int n, a, status[21], maxi=0;
std::vector<int> like[21], dislike[21];
std::set<int> current, curlike, curdis;

void rec(int pos) {
    if(pos==n+1) {
    	int conflict=0;
    	curlike.clear();
    	curdis.clear();
    	set<int>::iterator pos=current.begin(), pend=current.end();
    	for(; pos!=pend; pos++) {
    		int member=*pos, i, lsize=like[member].size(), dsize=dislike[member].size();
    		curlike.insert(member);
    		for(int i=0; i<lsize; i++) {
    			curlike.insert(like[member][i]);
    		}
    		for(int i=0; i<dsize; i++) {
    			curdis.insert(dislike[member][i]);
    		}
    	}

    	if(curlike.size()==current.size() && curlike.size()+curdis.size()==n) {
    		set<int>::iterator lpos=curlike.begin(), lend=curlike.end(),
    			 dpos=curdis.begin(), dend=curdis.end();
    		while(lpos!=lend && dpos!=dend) {
    			if(*lpos==*dpos) {conflict=1; break;}
    			else if(*lpos<*dpos) lpos++;
    			else dpos++;
    		}
    		if (conflict) cout << "conflict" << endl;
    		if(!conflict && current.size()>maxi) maxi=current.size();
    	}
    	return;
    }

    rec(pos+1);
    current.insert(pos);
    rec(pos+1);
    current.erase(pos);
}

int main() {
	while(sc("%d %d", &n, &a)==2) {
        if(n==0 && a==0) break;

		for(int i=1; i<=n; i++) {
			like[i].clear();
			dislike[i].clear();
			status[i]=0;
		}
		int u, v;
		for(int i=0; i<a; i++) {
			sc("%d %d", &u, &v);
			if(v>0) like[u].pb(v);
			else dislike[u].pb(0-v);
		}
		maxi=0;
		rec(1);
		cout << maxi << endl;
	}
	return 0;
}
