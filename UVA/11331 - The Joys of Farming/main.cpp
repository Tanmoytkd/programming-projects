#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int b, c, a, totalfield, res=0, maxlen=0, sum=0, imax=0, conflict=0, group[2002], one=0, two=0;
vector<int> ONE, TWO, graph[2002];

void run(int pos) {
	if(res) return;
	if(pos==maxlen) {
		int first=sum, second;
		second=imax-sum;
		if(first>second) swap(first, second);
		if(first<=b && second<=c) res=1;
		return;
	}
	if(sum>((imax/2)+(imax&1))) return;


	sum+=ONE[pos];
	run(pos+1);
	sum-=ONE[pos];
	if(res) return;

	if(ONE[pos]!=TWO[pos]) {
		sum+=TWO[pos];
		run(pos+1);
		sum-=TWO[pos];
	}
}

void rec(int pos) {
	if(conflict) return;
	int value = (group[pos]==1) ? 2:1;

	int len=graph[pos].size();
	for(int i=0; i<len; i++) {
		int element=graph[pos][i];
		if(group[element]==group[pos]) {
			conflict=1;
			break;
		}

		if(!group[element]) {
			group[element]=value;
			if(value==1) one++;
			else two++;
			imax++;
			rec(element);
		}

	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		sc("%d%d%d", &b, &c, &a);
		if(b>c) swap(b, c);

        imax=0;
        conflict=0;

		totalfield=b+c+1;

		for(int i=0; i<totalfield; i++) {
			 group[i]=0;
			 graph[i].clear();
		}
        ONE.clear();
        TWO.clear();

        int u, v;
		while(a--) {
			sc("%d %d", &u, &v);
			graph[u].pb(v);
			graph[v].pb(u);
		}

		for(int pos=1; pos<totalfield; pos++) {
			if(conflict) break;
			if(graph[pos].empty()) continue;
			if(!group[pos]) {
				one=0;
				two=0;

				//check[pos]=1;
				group[pos]=1;
				one++;
				imax++;

				rec(pos);

				//if(one>two) swap(one, two);

				ONE.pb(one);
				TWO.pb(two);
			}
		}


		if(conflict) {
			pf("no\n");
			continue;
		}
		else {
			maxlen=ONE.size();
			sum=0;
			res=0;
			run(0);
			if(res) pf("yes\n");
			else pf("no\n");
		}
	}
	return 0;
}
