#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


vector<int>edge[155];
int visited[155];

void dfs(int node) {

    vector<int> & e=edge[node];
    FOR(i, e.size()) {
        if(!visited[e[i]]) {
            visited[e[i]]=1;
            dfs(e[i]);
        }
    }
}

int main()
{
    int t, tst = 1;
    int n;
    vector<int> d;
    while(sf1(n) && n) {
        FOR(i, 155) edge[i]=d;
        memset(visited, 0, sizeof visited);
        int i;
        while(sf1(i) && i) {
            int j;
            while(sf1(j) && j) {
                edge[i].pb(j);
            }
        }

//        FOR1(i, n) {
//            cout << i << endl;
//            cout << "\t";
//            FOR(j, edge[i].size()) cout << edge[i][j] << " ";
//            cout << endl;
//        }

        int x;
        sf1(x);
        while(x--) {
            memset(visited, 0, sizeof visited);
            int start;
            sf1(start);
            dfs(start);

            int cnt=0;
            vector<int> inv;
            FOR1(i, n) {
                if(visited[i]==0) {
                    cnt++;
                    inv.pb(i);
                }
            }

            cout << cnt;
            FOR(i, inv.size()) {
                pf(" %d", inv[i]);
            }
            puts("");

        }


    }


    return 0;
}
