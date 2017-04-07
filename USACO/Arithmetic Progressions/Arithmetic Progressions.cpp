/*
ID: tanmoyk2
PROG: ariprog
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int mark[1000000];

int n;
int cnt=0;
vector<pii> res;

bool fn(pii a, pii b) {
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

void go(int start, int current, int diff, int pos) {
    if(pos==n) {
        res.push_back(pii(start, diff));
        return;
    }

    int next=current+diff;
    if(!mark[next]) return;
    go(start, current+diff, diff, pos+1);
}

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    fin >> n;
    int m;
    fin >> m;
    set<int> s;
    for(int i=0; i<=m; i++)
        for(int j=0; j<=m; j++) {
            int num = (i*i + j*j);
            s.insert(num);
            mark[num]=1;
        }


    vector<int> v;
    v.insert(v.end(), s.begin(), s.end());

    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            go(v[i], v[i], v[j]-v[i], 1);
        }
    }

    sort(res.begin(), res.end(), fn);
    if(res.size()==0) fout << "NONE" << endl;
    for(int i=0; i<res.size(); i++) {
        fout << res[i].first << " " << res[i].second << "\n";
    }

    return 0;
}
