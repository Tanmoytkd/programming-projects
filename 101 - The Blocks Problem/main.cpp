#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int pos[25];
std::vector<int> stk[25];

int main() {
	int n, a, b;
	char action[5], type[5];
	while(sc("%d", &n)==1) {
		for(int i=0; i<n; i++) {
			pos[i]=i;
			stk[i].resize(1, i);
		}

		while(1) {
			sc("%s", action);
			if(action[0]=='q') break;
			sc("%d %s %d", &a, type, &b);
			if(pos[a]==pos[b]) continue;
			std::vector<int> &avec=stk[pos[a]];
			std::vector<int> &bvec=stk[pos[b]];
			std::vector<int>::iterator apos=find(avec.begin(), avec.end(), a);
			std::vector<int>::iterator bpos=find(bvec.begin(), bvec.end(), b);
			std::vector<int>::iterator it;

			if(action[0]=='m') {
				for(it=apos+1; it!=avec.end(); it++) {
					pos[*it]=*it;
					stk[*it].pb(*it);
				}
				avec.resize(apos-avec.begin()+1);
			}
			if(type[3]=='o') {
				for(it=bpos+1; it!=bvec.end(); it++) {
					pos[*it]=*it;
					stk[*it].pb(*it);
				}
				bvec.resize(bpos-bvec.begin()+1);
			}

			bvec.insert(bvec.end(), apos, avec.end());
			for(it=apos; it!=avec.end(); it++) pos[*it]=pos[b];

			if(apos==avec.begin()) avec.clear();
			else avec.resize(apos-avec.begin());
		}



		for(int i=0; i<n; i++) {
			pf("%d:", i);
			int len=stk[i].size();
			for(int j=0; j<len; j++) {
				pf(" %d", stk[i][j]);
			}
			pf("\n");
		}
	}


	return 0;
}
