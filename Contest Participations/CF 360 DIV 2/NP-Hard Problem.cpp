#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int check[100002], group[100002], newcheck[100002];
vector<int> graph[100002];
set<int> a, b;

int conflict=0;

void run(int node) {
    if(conflict) return;
    if(newcheck[node]) return;

    int len=graph[node].size();
    int value = (group[node]==1) ? 2:1;

    for(int pos=0; pos<len; pos++) {
        int element=graph[node][pos];
        if(group[element]==group[node]) {
            conflict=1;
            break;
        }
        check[element]=1;
        group[element]=value;
        if(value==1) a.insert(element);
        else if(value==2) b.insert(element);
        newcheck[node]=1;
        if(!newcheck[element]) run(element);
    }
}

int main() {
	int n, m;
	cin >> n >> m;
	int u, v;
	while(m--) {
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}



	for(int i=1; i<=n; i++) {
		if(conflict) break;
		if(graph[i].size()==0) continue;

		if(!check[i]) {
			check[i]=1;
			group[i]=1;
			a.insert(i);
		}


        run(i);
	}

	if(conflict) cout << -1 << endl;
	else {
		int alen=a.size(), blen=b.size();
		if(alen>blen) {
            swap(alen, blen);
            a.swap(b);
		}

		cout << alen;
		for(set<int>::iterator it=a.begin(), ite=a.end(); it!=ite; it++)
            cout << " \n"[it==a.begin()] << *it;
        cout << endl;
		cout << blen;
		for(set<int>::iterator it=b.begin(), ite=b.end(); it!=ite; it++)
            cout << " \n"[it==b.begin()] << *it;
        cout << endl;
	}

	return 0;
}
