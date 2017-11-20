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
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
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
map<string, int> mp;
map<int, string> x;
int n;
int low[200], dis[200], fin[200], visit[200], child[200];
set<string> res;
vector<int> edge[200];
int timer=0;
void dfs(int node, int parent) {
    dis[node]=timer++;
    low[node]=dis[node];
    visit[node]=1;
    vector<int> & e = edge[node];
    FOR(i, e.size()) {
        int newnode=e[i];
        if(newnode==parent) continue;

        if(visit[newnode]) {
            low[node]=min(low[node], low[newnode]);
            continue;
        }
        else {
            child[node]++;
            dfs(newnode, node);
            low[node]=min(low[node], low[newnode]);
            if(low[newnode]>low[node]) {
                res.insert(x[node]);
            }
        }
    }
    fin[node]=timer++;
}

int main()
{
        #ifdef TKD
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif

    int t, tst = 1;
    while(sf1(n)==1 && n) {
        mem(visit, 0);
        mem(child, 0);
        res.clear();
        mp.clear();
        x.clear();
        string s;
        FOR1(i, n) {
            cin >> s;
            mp[s]=i;
            x[i]=s;
            edge[i].clear();
        }

        int m;
        sf1(m);
        while(m--) {
            string s, d;
            cin >> s >> d;
            int id1=mp[s], id2=mp[d];
            edge[id1].pb(id2);
            edge[id2].pb(id1);
        }

        int timer=0;
        FOR1(i, n) {
            if(visit[i]) continue;
            dfs(i, 0);
            if(child[i]>1) res.insert(x[i]);
        }
        if(tst!=1) puts("");
        pf("City map #%d: %d camera(s) found\n", tst++, res.size());
        for(string x : res) {
            cout << x << endl;
        }
    }
    return 0;
}
