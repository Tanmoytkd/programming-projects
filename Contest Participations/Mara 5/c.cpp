/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

#define mod 1000000007

int diff(const string & s1, const string & s2) {
    if(s1.length()!=s2.length()) return INT_MAX;
    int cnt=0;
    FOR(i, s1.length()) {
        if(s1[i]!=s2[i]) cnt++;
    }
    return cnt;
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif


    int t;
    int first=1;
    sf1(t);
    while(t--) {
        if(first) first=0;
        else puts("");


        vector<string> words;
        string str;
        while(cin >> str && str[0]!='*') {
            words.pb(str);
        }

//        for(int i=0; i<words.size(); i++) {
//            cout << words[i] << endl;
//        }

        map<string, vector<string> > mp;
        FOR(i, words.size()) {
            for(int j=i+1; j<words.size(); j++) {
                if(diff(words[i], words[j])==1) {
                    mp[words[i]].pb(words[j]);
                    mp[words[j]].pb(words[i]);
                }
            }
        }

        string line, src, dest;
        getline(cin,line);
        while(getline(cin, line) && line.length()!=0) {
            stringstream ss(line);
            ss >> src >> dest;

            if(src==dest) {
                cout << src << " " << dest << 0 << endl;
                continue;
            }
            map<string, int> level;
            queue<string> q;
            q.push(src);
            level[src]=1;

            int res=-1;

            while(!q.empty() && res==-1) {
                string & s = q.front();
                int lev=level[s];
                q.pop();

                vector<string> & edge = mp[s];
                FOR(i, edge.size()) {
                    if(edge[i]==dest) {
                        res=lev;
                        break;
                    }
                    if(level[edge[i]]) continue;
                    level[edge[i]]=lev+1;
                    q.push(edge[i]);
                }
            }
            cout << src << " " << dest << " " << res << endl;
        }
    };

    return 0;
}
