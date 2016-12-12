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

string src, dest;

int mark[55][5][300];
int n;


int invalid(const string & str) {
    int ret=0;
    FOR(x, n) {
        int c[3];
        FOR(i, 3) c[i]=mark[x][i][str[i]];
        int res =  (c[0] && c[1] && c[2]);
        ret = ret || res;
    }
    return ret;
}


int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif
    int test;
    sf1(test);

    FOR1(t, test) {
        cin >> src >> dest;

        memset(mark, 0, sizeof mark);

        sf1(n);
        char str[300];
        FOR(cnt, n) {
            FOR(i, 3) {
                sf("%s", str);
                int len=strlen(str);
                FOR(j, len) {
                    mark[cnt][i][str[j]]=1;
                }
            }
        }

//        cout << invalid(src) << endl;



        if(invalid(src) || invalid(dest)) {
            cout << "Case " << t << ": " << -1 << endl;
            continue;
        }
        if(src==dest) {
            cout << "Case " << t << ": " << 0 << endl;
            continue;
        }


        int res=-1;

        map<string, int> level;
        queue<string> q;
        level[src]=1;
        q.push(src);
        while(!q.empty()) {
            if(res!=-1) break;
            string s=q.front();
            q.pop();

            int lev=level[s];

            string nxt[6];
            FOR(i, 6) nxt[i]=s;

            nxt[0][0]++;
            nxt[1][0]--;
            nxt[2][1]++;
            nxt[3][1]--;
            nxt[4][2]++;
            nxt[5][2]--;

            FOR(i, 6) {
                FOR(j, 3) {
                    if(nxt[i][j]<'a') nxt[i][j]+=26;
                    if(nxt[i][j]>'z') nxt[i][j]-=26;
                }
            }

            FOR(i, 6) {
                if(!invalid(nxt[i]) && level[nxt[i]]==0) {
                    level[nxt[i]]=lev+1;
                    q.push(nxt[i]);
                    if(nxt[i]==dest) res=lev;
                }
            }
        }
        cout << "Case " << t << ": " << res << endl;
    }
    return 0;
}
