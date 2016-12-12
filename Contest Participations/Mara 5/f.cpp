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

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int t, test=1;
    sf1(t);
    while(t--) {
        int p, n;
        sf2(p,n);

        map<string, int > level;
        map<string, vector<string> > edge;
        char line[10000], namelist[10000];
        gets(line);
        while(p--) {
            gets(line);
            string  lst, fst;
            stringstream ss(line);
            vector<string> writers;
            while(ss >> lst >> fst) {
                char ch=fst[fst.length()-1];
                fst.erase(fst.length()-1);
                writers.pb(lst + " " + fst);
                if(ch==':') break;
            }
            FOR(i, writers.size()) {
                FOR(j, writers.size()) {
                    edge[writers[i]].pb(writers[j]);
                }
            }
        }

        string src="Erdos, P.";
        queue<string> q;
        level[src]=1;
        q.push(src);

        while(!q.empty()) {
            string top=q.front();
            int lev=level[top];
            q.pop();

            vector<string> & e = edge[top];

            FOR(i, e.size()) {
                if(level[e[i]]) continue;
                level[e[i]]=lev+1;
                q.push(e[i]);
            }
        }

        pf("Scenario %d\n", test++);
        while(n--) {
            string name;
            getline(cin, name);
            int res=level[name];
            cout << name << " ";
            if(res) cout << res-1 << endl;
            else cout << "infinity" << endl;
        }
    }
    return 0;
}
