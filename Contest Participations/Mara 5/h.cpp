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

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

struct node {
    int val;
    int dis;
    int fin;
} school[105];

int graph[105][105];

int visited[105], timer=0;
vector<int> edge[105];

vector<int> root, leaf;

bool func(node a, node b) {
    return a.fin>b.fin;
}

void dfs(int nd) {
    school[nd].dis=++timer;
    visited[nd]=1;

    vector<int> & e = edge[nd];
    FOR(i, e.size()) {
        if(visited[e[i]]) continue;
        dfs(e[i]);
    }

    school[nd].fin=++timer;

    if((school[nd].fin-school[nd].dis)==1 && root.size()) {
        int src=root.back();
        if(!graph[nd][src]) leaf.pb(nd);
    }
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int n;
    sf1(n);

    FOR1(i, n) {
        school[i].val=i;
//        sch[i].val=i;
        int j;
        while(sf1(j) && j) {
            edge[i].pb(j);
            graph[i][j]=1;
        }
    }

    if(n==1) {
        cout << n << endl << 0 << endl;
        return 0;
    }

    FOR1(k, n) {
        FOR1(i, n) {
            FOR1(j, n) {
                if(graph[i][k] && graph[k][j]) graph[i][j]=1;
            }
        }
    }

    FOR1(i, n) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    sort(school+1, school+n+1, func);
    memset(visited, 0, sizeof visited);
    leaf.clear();
    root.clear();

    int timer=0, cnt=0, extra=0;
    FOR1(i, n) {
        int index=school[i].val;
        if(!visited[index]) {
            root.pb(index);
            dfs(index);
            cnt+=leaf.size();

            if(leaf.size()==0) extra++;
            leaf.clear();
        }
    }

    if(root.size()!=1) cnt+=extra;

    //FOR(i, leaf.size()) cout << leaf[i] << " leaf\n";

    cout << root.size() << endl << cnt << endl;;
//    int cnt=0;
//    FOR(i, leaf.size()) {
//        FOR(j, root.size()) {
//            int strt=leaf[i], fini=root[j];
//            if(strt==fini) continue;
//            if(!graph[strt][fini]) {
//                cnt++;
//            }
//        }
//    }
//    cout << cnt << endl;
    return 0;
}
