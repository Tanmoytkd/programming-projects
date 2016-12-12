/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits.h>

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
#define mx 100007

int v[mx], in[mx], out[mx], maxpro[mx];
vector<int> edge[mx];

int dfs(int node, int prev) {
    prev+=v[node];
    if(out[node]==0) return prev;

    if(maxpro[node]==INT_MIN) {
        vector<int> & e = edge[node];
        FOR(i, e.size()) {
            int newnode=e[i];
            int maxi=dfs(newnode, 0);
            if(maxi>maxpro[node]) maxpro[node]=maxi;
        }
    }

    //cout << node << "\t" << maxpro[node] << endl;
    return prev+maxpro[node];
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif
    int n, m;
    vector<int> dk;
    while(sf2(n,m)==2) {

        FOR1(i, n) {
            sf1(v[i]);
            edge[i]=dk;
            in[i]=0;
            out[i]=0;
            maxpro[i]=INT_MIN;
        }



        int x,y;
        while(m--) {
            sf2(x,y);
            out[x]++;
            in[y]++;
            edge[x].pb(y);
        }

//        FOR1(i, n) {
//            cout << v[i] << "\t" << in[i] << "\t" << out[i] << "\t" << edge[i].size() << endl;
//        }

        int profit=INT_MIN;
        FOR1(i, n) {
            if(in[i]==0) {
                int pro=dfs(i, 0);
                if(pro>profit) {
                    profit=pro;
//                    cout << i << endl;
                }
            }
        }

        pf1(profit);
    }

    return 0;
}
