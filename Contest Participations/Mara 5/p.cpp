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

char graph[256][256], visit[256], occur[256];
int counter=0;

void dfs(int i) {
    visit[i]=1;
    for(int j='A'; j<='Z'; j++) {
        if(!visit[j] && graph[i][j]) dfs(j);
    }
}

int main() {
    #ifdef TKD
    freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif

    int t;
    sf1(t);

    char str[256];
    gets(str);
    gets(str);

    int first=1;

    while(t--) {
        memset(graph, 0, sizeof graph);
        memset(visit, 0, sizeof visit);
        memset(occur, 0, sizeof occur);
        gets(str);
        for(int i='A'; i<=str[0]; i++) occur[i]=1;

        while(gets(str)!=NULL && strlen(str)==2) {
            graph[str[0]][str[1]]=1;
            graph[str[1]][str[0]]=1;
            occur[str[0]]=1;
            occur[str[1]]=1;
        }

        counter=0;

        for(int i='A'; i<='Z'; i++) {
            if(visit[i]) continue;
            if(!occur[i]) continue;
            dfs(i);
            counter++;
        }

        if(!first) puts("");
        else first=0;
        pf1(counter);
    }
    return 0;
}
